SET(SOURCES screens/ui_leagueScreen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    fonts/ui_font_Font1.c)

add_library(ui ${SOURCES})
