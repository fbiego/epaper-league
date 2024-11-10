
# ePaper League

A project to display soccer league standings on a 400x300 ePaper display.

## Overview

This project uses an ESP32-based ePaper display to fetch and display live soccer league standings. Data is retrieved from an API and displayed on the 4.2" ePaper display in black and white. Due to limited screen space, the table is scrollable using a side switch.

## Features

- Fetches live soccer standings data from [Football-Data API](https://api.football-data.org/v4/competitions/PL/standings)
- Displays league standings on a 400x300 ePaper display
- Scrolls the table using a side switch for extended lists

## Requirements

1. ESP32 4.2" ePaper Display (400x300 resolution)
   - [`Elecrow ePaper Display`](https://www.elecrow.com/crowpanel-esp32-4-2-e-paper-hmi-display-with-400-300-resolution-black-white-color-driven-by-spi-interface.html)
2. Football-Data API key
   - [Sign up for an API key](https://docs.football-data.org/general/v4/index.html)
