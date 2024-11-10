// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 9.1.0
// Project name: EPL

#include "../ui.h"

void ui_leagueScreen_screen_init(void)
{
    ui_leagueScreen = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_leagueScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_leagueScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_leagueScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_headerPanel = lv_obj_create(ui_leagueScreen);
    lv_obj_set_width(ui_headerPanel, 400);
    lv_obj_set_height(ui_headerPanel, 28);
    lv_obj_set_align(ui_headerPanel, LV_ALIGN_TOP_MID);
    lv_obj_remove_flag(ui_headerPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_headerPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_headerPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_headerPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_headerPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_headerPanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_headerPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_headerPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_headerPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_headerPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leagueName = lv_label_create(ui_headerPanel);
    lv_obj_set_width(ui_leagueName, 171);
    lv_obj_set_height(ui_leagueName, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_leagueName, 5);
    lv_obj_set_y(ui_leagueName, 0);
    lv_obj_set_align(ui_leagueName, LV_ALIGN_LEFT_MID);
    lv_label_set_long_mode(ui_leagueName, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_leagueName, "Premier League");
    lv_obj_set_style_text_font(ui_leagueName, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_playedTitle = lv_label_create(ui_headerPanel);
    lv_obj_set_width(ui_playedTitle, 25);
    lv_obj_set_height(ui_playedTitle, 20);
    lv_obj_set_x(ui_playedTitle, -175);
    lv_obj_set_y(ui_playedTitle, 0);
    lv_obj_set_align(ui_playedTitle, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_playedTitle, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_playedTitle, "P");
    lv_obj_set_style_text_color(ui_playedTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_playedTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_playedTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_playedTitle, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_playedTitle, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_playedTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_playedTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wonTitle = lv_label_create(ui_headerPanel);
    lv_obj_set_width(ui_wonTitle, 25);
    lv_obj_set_height(ui_wonTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wonTitle, -150);
    lv_obj_set_y(ui_wonTitle, 0);
    lv_obj_set_align(ui_wonTitle, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_wonTitle, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_wonTitle, "W");
    lv_obj_set_style_text_align(ui_wonTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_wonTitle, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_drawTitle = lv_label_create(ui_headerPanel);
    lv_obj_set_width(ui_drawTitle, 25);
    lv_obj_set_height(ui_drawTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_drawTitle, -125);
    lv_obj_set_y(ui_drawTitle, 0);
    lv_obj_set_align(ui_drawTitle, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_drawTitle, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_drawTitle, "D");
    lv_obj_set_style_text_align(ui_drawTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_drawTitle, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lostTitle = lv_label_create(ui_headerPanel);
    lv_obj_set_width(ui_lostTitle, 25);
    lv_obj_set_height(ui_lostTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lostTitle, -100);
    lv_obj_set_y(ui_lostTitle, 0);
    lv_obj_set_align(ui_lostTitle, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_lostTitle, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_lostTitle, "L");
    lv_obj_set_style_text_align(ui_lostTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lostTitle, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pointsTitle = lv_label_create(ui_headerPanel);
    lv_obj_set_width(ui_pointsTitle, 25);
    lv_obj_set_height(ui_pointsTitle, 20);
    lv_obj_set_x(ui_pointsTitle, -75);
    lv_obj_set_y(ui_pointsTitle, 0);
    lv_obj_set_align(ui_pointsTitle, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_pointsTitle, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_pointsTitle, "Pt");
    lv_obj_set_style_text_color(ui_pointsTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_pointsTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_pointsTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_pointsTitle, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_pointsTitle, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pointsTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_scoredTitle = lv_label_create(ui_headerPanel);
    lv_obj_set_width(ui_scoredTitle, 25);
    lv_obj_set_height(ui_scoredTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_scoredTitle, -50);
    lv_obj_set_y(ui_scoredTitle, 0);
    lv_obj_set_align(ui_scoredTitle, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_scoredTitle, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_scoredTitle, "GF");
    lv_obj_set_style_text_align(ui_scoredTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_scoredTitle, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_concededTitle = lv_label_create(ui_headerPanel);
    lv_obj_set_width(ui_concededTitle, 25);
    lv_obj_set_height(ui_concededTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_concededTitle, -25);
    lv_obj_set_y(ui_concededTitle, 0);
    lv_obj_set_align(ui_concededTitle, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_concededTitle, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_concededTitle, "GA");
    lv_obj_set_style_text_align(ui_concededTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_concededTitle, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_differenceTitle = lv_label_create(ui_headerPanel);
    lv_obj_set_width(ui_differenceTitle, 25);
    lv_obj_set_height(ui_differenceTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_differenceTitle, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_differenceTitle, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_differenceTitle, "GD");
    lv_obj_set_style_text_align(ui_differenceTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_differenceTitle, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_tableList = lv_obj_create(ui_leagueScreen);
    lv_obj_set_width(ui_tableList, 400);
    lv_obj_set_height(ui_tableList, 270);
    lv_obj_set_align(ui_tableList, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_tableList, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_tableList, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_scrollbar_mode(ui_tableList, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ui_tableList, LV_DIR_VER);
    lv_obj_set_style_radius(ui_tableList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_tableList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_tableList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_tableList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_tableList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_tableList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_tableList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_tableList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_teamPanel = lv_obj_create(ui_tableList);
    lv_obj_set_width(ui_teamPanel, 400);
    lv_obj_set_height(ui_teamPanel, 27);
    lv_obj_set_align(ui_teamPanel, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_teamPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_teamPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_teamPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_teamPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_teamPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_teamPanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_teamPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_teamPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_teamPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_teamPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pos = lv_label_create(ui_teamPanel);
    lv_obj_set_width(ui_pos, 25);
    lv_obj_set_height(ui_pos, 25);
    lv_obj_set_x(ui_pos, 2);
    lv_obj_set_y(ui_pos, 0);
    lv_obj_set_align(ui_pos, LV_ALIGN_LEFT_MID);
    lv_label_set_long_mode(ui_pos, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_pos, "1");
    lv_obj_set_style_text_color(ui_pos, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_pos, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_pos, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_pos, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pos, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_name = lv_label_create(ui_teamPanel);
    lv_obj_set_width(ui_name, 165);
    lv_obj_set_height(ui_name, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_name, 30);
    lv_obj_set_y(ui_name, 0);
    lv_obj_set_align(ui_name, LV_ALIGN_LEFT_MID);
    lv_label_set_long_mode(ui_name, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_name, "Liverpool");
    lv_obj_set_style_text_font(ui_name, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_played = lv_label_create(ui_teamPanel);
    lv_obj_set_width(ui_played, 25);
    lv_obj_set_height(ui_played, 25);
    lv_obj_set_x(ui_played, -175);
    lv_obj_set_y(ui_played, 0);
    lv_obj_set_align(ui_played, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_played, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_played, "10");
    lv_obj_set_style_text_color(ui_played, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_played, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_played, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_played, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_played, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_played, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_won = lv_label_create(ui_teamPanel);
    lv_obj_set_width(ui_won, 25);
    lv_obj_set_height(ui_won, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_won, -150);
    lv_obj_set_y(ui_won, 0);
    lv_obj_set_align(ui_won, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_won, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_won, "8");
    lv_obj_set_style_text_color(ui_won, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_won, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_won, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_won, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_draw = lv_label_create(ui_teamPanel);
    lv_obj_set_width(ui_draw, 25);
    lv_obj_set_height(ui_draw, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_draw, -125);
    lv_obj_set_y(ui_draw, 0);
    lv_obj_set_align(ui_draw, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_draw, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_draw, "1");
    lv_obj_set_style_text_align(ui_draw, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_draw, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lost = lv_label_create(ui_teamPanel);
    lv_obj_set_width(ui_lost, 25);
    lv_obj_set_height(ui_lost, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lost, -100);
    lv_obj_set_y(ui_lost, 0);
    lv_obj_set_align(ui_lost, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_lost, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_lost, "1");
    lv_obj_set_style_text_color(ui_lost, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lost, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_lost, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lost, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_points = lv_label_create(ui_teamPanel);
    lv_obj_set_width(ui_points, 25);
    lv_obj_set_height(ui_points, 25);
    lv_obj_set_x(ui_points, -75);
    lv_obj_set_y(ui_points, 0);
    lv_obj_set_align(ui_points, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_points, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_points, "25");
    lv_obj_set_style_text_color(ui_points, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_points, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_points, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_points, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_points, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_points, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_scored = lv_label_create(ui_teamPanel);
    lv_obj_set_width(ui_scored, 25);
    lv_obj_set_height(ui_scored, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_scored, -50);
    lv_obj_set_y(ui_scored, 0);
    lv_obj_set_align(ui_scored, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_scored, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_scored, "19");
    lv_obj_set_style_text_color(ui_scored, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_scored, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_scored, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_scored, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_conceded = lv_label_create(ui_teamPanel);
    lv_obj_set_width(ui_conceded, 25);
    lv_obj_set_height(ui_conceded, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_conceded, -25);
    lv_obj_set_y(ui_conceded, 0);
    lv_obj_set_align(ui_conceded, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_conceded, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_conceded, "6");
    lv_obj_set_style_text_align(ui_conceded, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_conceded, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_difference = lv_label_create(ui_teamPanel);
    lv_obj_set_width(ui_difference, 25);
    lv_obj_set_height(ui_difference, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_difference, LV_ALIGN_RIGHT_MID);
    lv_label_set_long_mode(ui_difference, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_difference, "13");
    lv_obj_set_style_text_color(ui_difference, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_difference, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_difference, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_difference, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

}