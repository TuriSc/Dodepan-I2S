#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "config.h"
#include "ssd1306.h"        // https://github.com/daschr/pico-ssd1306
#include "state.h"

// Include assets
#include "display_fonts.h"
#include "display_strings.h"
#include "intro.h"
#include "icon_off.h"
#include "icon_on_x.h"
#include "icon_on_y.h"
#include "icon_on_x_y.h"
#include "icon_low_batt.h"

void display_init(ssd1306_t *p) {
    p->external_vcc=false;
    ssd1306_init(p, SSD1306_WIDTH, SSD1306_HEIGHT, SSD1306_ADDRESS, SSD1306_I2C_PORT);
    ssd1306_clear(p);
    ssd1306_show(p);
}

#define ICON_MARGIN_X ((SSD1306_WIDTH / 2) - (32 / 2))
void intro_animation(ssd1306_t *p, void (*callback)(void)) {
    for(uint8_t current_frame=0; current_frame < INTRO_FRAMES_NUM; current_frame++) {
        ssd1306_bmp_show_image_with_offset(p, intro_frames[current_frame], INTRO_FRAME_SIZE, ICON_MARGIN_X, 0);
        ssd1306_show(p);
        busy_wait_ms(42); // About 24fps
        ssd1306_clear(p);
    }
    callback();
}

#define OFFSET_X    32
#define CHAR_W      7 // Includes spacing
void display_draw(ssd1306_t *p) {

    state_t* state = get_state();

    ssd1306_clear(p);
    switch(state->context) {
        case CTX_KEY:
        case CTX_SCALE:
        case CTX_INSTRUMENT:
        {
            // Key
            ssd1306_draw_string_with_font(p, 0, 4, 1, key_font, note_names[state->tonic]);
            if(state->is_alteration) { ssd1306_draw_string_with_font(p, 15, 0, 1, diesis_font, diesis); }
            ssd1306_draw_string_with_font(p, 15, 16, 1, octave_font, octave_names[state->octave]);

            // Scale and instrument
            ssd1306_draw_string_with_font(p, OFFSET_X, 21, 1, spaced_font, scale_names[state->scale]);
            ssd1306_draw_string_with_font(p, OFFSET_X, 4, 1, spaced_font, instrument_names[state->instrument]);
            uint8_t scale_name_width = strlen(scale_names[state->scale]);
            uint8_t instrument_name_width = strlen(instrument_names[state->instrument]);

            // Overflow menu. Not interactive, but it's there for good UX,
            // letting users know that there are more pages
            ssd1306_draw_line(p, 122, 0, 127, 0);
            ssd1306_draw_line(p, 122, 1, 127, 1);
            ssd1306_draw_line(p, 122, 3, 127, 3);
            ssd1306_draw_line(p, 122, 4, 127, 4);
            ssd1306_draw_line(p, 122, 6, 127, 6);
            ssd1306_draw_line(p, 122, 7, 127, 7);
            
            // Draw underline
            switch(state->context) {
                case CTX_KEY:
                    ssd1306_draw_line(p, 0, 30, 25, 30);
                    ssd1306_draw_line(p, 0, 31, 25, 31);
                break;
                case CTX_SCALE:
                    ssd1306_draw_line(p, OFFSET_X, 30, OFFSET_X+CHAR_W*scale_name_width, 30);
                    ssd1306_draw_line(p, OFFSET_X, 31, OFFSET_X+CHAR_W*scale_name_width, 31);
                break;
                case CTX_INSTRUMENT:
                    ssd1306_draw_line(p, OFFSET_X, 13, OFFSET_X+CHAR_W*instrument_name_width, 13);
                    ssd1306_draw_line(p, OFFSET_X, 14, OFFSET_X+CHAR_W*instrument_name_width, 14);
                break;
            }
        }
        break;
        case CTX_IMU_CONFIG:
            switch (state->imu_axes) {
                case 0x0:
                    ssd1306_bmp_show_image_with_offset(p, icon_off_data, icon_off_size, 48, 0);
                break;
                case 0x1:
                    ssd1306_bmp_show_image_with_offset(p, icon_on_x_data, icon_on_x_size, 48, 0);
                break;
                case 0x2:
                    ssd1306_bmp_show_image_with_offset(p, icon_on_y_data, icon_on_y_size, 48, 0);
                break;
                case 0x3:
                    ssd1306_bmp_show_image_with_offset(p, icon_on_x_y_data, icon_on_x_y_size, 48, 0);
                break;
            }
        break;
        case CTX_VOLUME:
        {
            // Draw the volume bars
            uint8_t increments = 9; // 0 to 8
            uint8_t gap = (128 / increments / 4);
            uint8_t width = 128 / increments - gap;

            for (uint8_t i = 1; i < increments; i++) {
                uint8_t x = i * width + i * gap;
                if(state->volume >= i) {
                    ssd1306_draw_square(p, x, 8, width, 16);
                } else {
                    ssd1306_draw_empty_square(p, x, 8, width, 16);
                }
            }
        }
        break;
    }


    if(state->low_batt) {
        // Clear an outline around the icon to avoid overlaps
        ssd1306_clear_square(p, 119, 17, 9, 15);
        ssd1306_bmp_show_image_with_offset(p, icon_low_batt_data, icon_low_batt_size, 121, 18);
    }

    ssd1306_show(p);
}