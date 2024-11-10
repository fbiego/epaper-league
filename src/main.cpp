#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include "ChronosESP32.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "lvgl.h"
#include "Button2.h"
#include "ui/ui.h"

#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h>

GxEPD2_BW<GxEPD2_420_GDEY042T81, GxEPD2_420_GDEY042T81::HEIGHT> display(GxEPD2_420_GDEY042T81(/*CS=5*/ 45, /*DC=*/46, /*RST=*/47, /*BUSY=*/48)); // GDEY042T81, 400x300, SSD1683 (no inking)

#define GxEPD2_DISPLAY_CLASS GxEPD2_BW
#define GxEPD2_DRIVER_CLASS GxEPD2_420_GDEY042T81 // GDEY042T81 400x300, SSD1683 (no inking)

#define SCR_WIDTH 400
#define SCR_HEIGHT 300
#define LVBUF ((SCR_WIDTH * SCR_HEIGHT / 8) + 8)

WiFiMulti wifiMulti;
ESP32Time rtc;
Button2 up;
Button2 down;

String url = "https://api.football-data.org/v4/competitions/PL/standings";
String token = "__API_KEY__";

static lv_display_t *lvDisplay;
// static uint8_t lvBuffer[2][LVBUF];
uint8_t *lvBuf;

bool screen, data; // flags for data

int lastUpdate = -1;

struct Team
{
  int pos;
  String name;
  int played;
  int won;
  int draw;
  int lost;
  int points;
  int scored;
  int conceded;
  int difference;
};

void my_disp_flush(lv_display_t *disp, const lv_area_t *area, unsigned char *data)
{
  int16_t width = area->x2 - area->x1 + 1;
  int16_t height = area->y2 - area->y1 + 1;
  display.drawImage((uint8_t *)data + 8, area->x1, area->y1, width, height);

  lv_display_flush_ready(disp);
}

void buttonHandler(Button2 &btn)
{
  if (btn == up){
    lv_obj_scroll_to(ui_tableList, 0, 0, LV_ANIM_OFF); // first half (0-10)
  }
  if (btn == down){
    lv_obj_scroll_to(ui_tableList, 0, 271, LV_ANIM_OFF); // second half (11-20)
  }
}

void addTeam(Team t)
{
  lv_obj_t *ui_teamPanel = lv_obj_create(ui_tableList);
  lv_obj_set_width(ui_teamPanel, 400);
  lv_obj_set_height(ui_teamPanel, 27);
  lv_obj_set_align(ui_teamPanel, LV_ALIGN_CENTER);
  lv_obj_remove_flag(ui_teamPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
  lv_obj_set_style_radius(ui_teamPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_teamPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_teamPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_teamPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_teamPanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_teamPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_teamPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_teamPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_teamPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_pos = lv_label_create(ui_teamPanel);
  lv_obj_set_width(ui_pos, 25);
  lv_obj_set_height(ui_pos, 25);
  lv_obj_set_x(ui_pos, 2);
  lv_obj_set_y(ui_pos, 0);
  lv_obj_set_align(ui_pos, LV_ALIGN_LEFT_MID);
  lv_label_set_long_mode(ui_pos, LV_LABEL_LONG_CLIP);
  lv_label_set_text_fmt(ui_pos, "%d", t.pos);
  lv_obj_set_style_text_color(ui_pos, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui_pos, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_pos, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_pos, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_name = lv_label_create(ui_teamPanel);
  lv_obj_set_width(ui_name, 165);
  lv_obj_set_height(ui_name, LV_SIZE_CONTENT); /// 1
  lv_obj_set_x(ui_name, 30);
  lv_obj_set_y(ui_name, 0);
  lv_obj_set_align(ui_name, LV_ALIGN_LEFT_MID);
  lv_label_set_long_mode(ui_name, LV_LABEL_LONG_CLIP);
  lv_label_set_text(ui_name, t.name.c_str());
  lv_obj_set_style_text_font(ui_name, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_played = lv_label_create(ui_teamPanel);
  lv_obj_set_width(ui_played, 25);
  lv_obj_set_height(ui_played, 25);
  lv_obj_set_x(ui_played, -175);
  lv_obj_set_y(ui_played, 0);
  lv_obj_set_align(ui_played, LV_ALIGN_RIGHT_MID);
  lv_label_set_long_mode(ui_played, LV_LABEL_LONG_CLIP);
  lv_label_set_text_fmt(ui_played, "%d", t.played);
  lv_obj_set_style_text_color(ui_played, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_played, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui_played, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_played, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_played, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_played, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_won = lv_label_create(ui_teamPanel);
  lv_obj_set_width(ui_won, 25);
  lv_obj_set_height(ui_won, LV_SIZE_CONTENT); /// 1
  lv_obj_set_x(ui_won, -150);
  lv_obj_set_y(ui_won, 0);
  lv_obj_set_align(ui_won, LV_ALIGN_RIGHT_MID);
  lv_label_set_long_mode(ui_won, LV_LABEL_LONG_CLIP);
  lv_label_set_text_fmt(ui_won, "%d", t.won);
  lv_obj_set_style_text_color(ui_won, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_won, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui_won, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_won, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_draw = lv_label_create(ui_teamPanel);
  lv_obj_set_width(ui_draw, 25);
  lv_obj_set_height(ui_draw, LV_SIZE_CONTENT); /// 1
  lv_obj_set_x(ui_draw, -125);
  lv_obj_set_y(ui_draw, 0);
  lv_obj_set_align(ui_draw, LV_ALIGN_RIGHT_MID);
  lv_label_set_long_mode(ui_draw, LV_LABEL_LONG_CLIP);
  lv_label_set_text_fmt(ui_draw, "%d", t.draw);
  lv_obj_set_style_text_align(ui_draw, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_draw, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_lost = lv_label_create(ui_teamPanel);
  lv_obj_set_width(ui_lost, 25);
  lv_obj_set_height(ui_lost, LV_SIZE_CONTENT); /// 1
  lv_obj_set_x(ui_lost, -100);
  lv_obj_set_y(ui_lost, 0);
  lv_obj_set_align(ui_lost, LV_ALIGN_RIGHT_MID);
  lv_label_set_long_mode(ui_lost, LV_LABEL_LONG_CLIP);
  lv_label_set_text_fmt(ui_lost, "%d", t.lost);
  lv_obj_set_style_text_color(ui_lost, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_lost, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui_lost, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_lost, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_points = lv_label_create(ui_teamPanel);
  lv_obj_set_width(ui_points, 25);
  lv_obj_set_height(ui_points, 25);
  lv_obj_set_x(ui_points, -75);
  lv_obj_set_y(ui_points, 0);
  lv_obj_set_align(ui_points, LV_ALIGN_RIGHT_MID);
  lv_label_set_long_mode(ui_points, LV_LABEL_LONG_CLIP);
  lv_label_set_text_fmt(ui_points, "%d", t.points);
  lv_obj_set_style_text_color(ui_points, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_points, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui_points, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_points, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_points, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_points, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_scored = lv_label_create(ui_teamPanel);
  lv_obj_set_width(ui_scored, 25);
  lv_obj_set_height(ui_scored, LV_SIZE_CONTENT); /// 1
  lv_obj_set_x(ui_scored, -50);
  lv_obj_set_y(ui_scored, 0);
  lv_obj_set_align(ui_scored, LV_ALIGN_RIGHT_MID);
  lv_label_set_long_mode(ui_scored, LV_LABEL_LONG_CLIP);
  lv_label_set_text_fmt(ui_scored, "%d", t.scored);
  lv_obj_set_style_text_color(ui_scored, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_scored, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui_scored, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_scored, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_conceded = lv_label_create(ui_teamPanel);
  lv_obj_set_width(ui_conceded, 25);
  lv_obj_set_height(ui_conceded, LV_SIZE_CONTENT); /// 1
  lv_obj_set_x(ui_conceded, -25);
  lv_obj_set_y(ui_conceded, 0);
  lv_obj_set_align(ui_conceded, LV_ALIGN_RIGHT_MID);
  lv_label_set_long_mode(ui_conceded, LV_LABEL_LONG_CLIP);
  lv_label_set_text_fmt(ui_conceded, "%d", t.conceded);
  lv_obj_set_style_text_align(ui_conceded, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_conceded, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_difference = lv_label_create(ui_teamPanel);
  lv_obj_set_width(ui_difference, 25);
  lv_obj_set_height(ui_difference, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(ui_difference, LV_ALIGN_RIGHT_MID);
  lv_label_set_long_mode(ui_difference, LV_LABEL_LONG_CLIP);
  lv_label_set_text_fmt(ui_difference, "%d", t.difference);
  lv_obj_set_style_text_color(ui_difference, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_difference, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui_difference, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui_difference, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void updateData()
{
  HTTPClient http;
  http.begin(url);
  http.addHeader("X-Auth-Token", token);
  int httpCode = http.GET();
  String payload = http.getString();
  if (httpCode == HTTP_CODE_OK)
  {
    Serial.println(payload);
    DynamicJsonDocument json(8192);
    deserializeJson(json, payload);
    String league = json["competition"]["name"].as<String>();
    
    lv_label_set_text(ui_leagueName, league.c_str());
    lv_obj_clean(ui_tableList); // clear the list in preparation of new data

    for (JsonVariant v : json["standings"][0]["table"].as<JsonArray>()){
      if (v.is<JsonObject>()){
        Team t;
        t.pos = v["position"].as<int>();
        t.name = v["team"]["shortName"].as<String>();
        t.played = v["playedGames"].as<int>();
        t.won = v["won"].as<int>();
        t.draw = v["draw"].as<int>();
        t.lost = v["lost"].as<int>();
        t.points = v["points"].as<int>();
        t.scored = v["goalsFor"].as<int>();
        t.conceded = v["goalsAgainst"].as<int>();
        t.difference = v["goalDifference"].as<int>();

        addTeam(t);
      }
    }


  }
  http.end();
}

static uint32_t my_tick(void)
{
  return millis();
}

void epd_setup()
{

  SPI.begin(12, -1, 11, 45);
  display.init(115200, true);
  if (display.pages() > 1)
  {
    delay(100);
    Serial.print("pages = ");
    Serial.print(display.pages());
    Serial.print(" page height = ");
    Serial.println(display.pageHeight());
    delay(1000);
  }
  // display.clearScreen(); return;
  //  first update should be full refresh
  delay(1000);
}

void setup()
{

  Serial.begin(115200);

  pinMode(7, OUTPUT);    // Set pin 7 to output mode
  digitalWrite(7, HIGH); // Set pin 7 to high level to activate the screen power
  pinMode(41, OUTPUT);

  WiFi.mode(WIFI_STA);
  // wifiMulti.addAP("__SSID__", "__PASS__");
  // wifiMulti.addAP("__SSID2__", "__PASS2__");
  // wifiMulti.addAP("__SSID3__", "__PASS3__");


  up.begin(6);
  down.begin(4);
  up.setClickHandler(buttonHandler);
  down.setClickHandler(buttonHandler);
  up.setLongClickDetectedHandler(buttonHandler);
  down.setLongClickDetectedHandler(buttonHandler);

  epd_setup();

  lv_init();
  lv_tick_set_cb(my_tick);

  lvDisplay = lv_display_create(SCR_WIDTH, SCR_HEIGHT);
  lv_display_set_flush_cb(lvDisplay, my_disp_flush);
  lvBuf = (uint8_t *)malloc(LVBUF);
  lv_display_set_buffers(lvDisplay, lvBuf, NULL, LVBUF, LV_DISPLAY_RENDER_MODE_PARTIAL);
  

  ui_init();


  lv_obj_clean(ui_tableList);
  lv_obj_t *info = lv_label_create(ui_tableList);
  lv_obj_set_width(info, 180);
  lv_obj_set_y(info, 100);
  lv_obj_set_height(info, LV_SIZE_CONTENT); /// 1
  lv_label_set_long_mode(info, LV_LABEL_LONG_WRAP);
  lv_obj_set_style_text_font(info, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_label_set_text(info, "\n\nWaiting for wifi to connect");
}

void loop()
{
  lv_timer_handler(); // Update the UI-
  delay(10);

  up.loop();
  down.loop();

  if (wifiMulti.run() == WL_CONNECTED)
  {
    digitalWrite(41, HIGH);

    if (lastUpdate != rtc.getHour())
    {
      // update once every hour
      lastUpdate = rtc.getHour();

      Serial.print("WiFi connected: ");
      Serial.print(WiFi.SSID());
      Serial.print(" ");
      Serial.println(WiFi.RSSI());

      updateData();
    }
  }
  else
  {
    digitalWrite(41, LOW);
  }
}