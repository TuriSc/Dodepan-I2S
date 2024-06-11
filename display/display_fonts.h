#ifndef DISPLAY_FONTS_H
#define DISPLAY_FONTS_H

const unsigned char key_font[] = {
    24, 13, 0, 65, 71,
    // A
    0xF8, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0x1F, 0x3C, 0x00, 0x0F, 0x3C, 0x00, 0x0F, 0x3C, 0x00, 0x0F, 0x3C, 0x00, 
    0x1F, 0x3C, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 
    0xF8, 0xFF, 0xFF,
    // B
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0x0F, 0x3C, 0xF0, 0x0F, 0x3C, 0xF0, 0x0F, 0x3C, 0xF0, 0x0F, 0x3C, 0xF0, 
    0x1F, 0x7E, 0xF8, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x7F, 0xFC, 0xFF, 0x3F, 
    0xF8, 0xE7, 0x1F,
    // C
    0xF8, 0xFF, 0x1F, 0xFC, 0xFF, 0x3F, 0xFE, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 
    0x1F, 0x00, 0xF8, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 
    0x1F, 0x00, 0xF8, 0xFF, 0xC3, 0xFF, 0xFE, 0xC3, 0x7F, 0xFC, 0xC3, 0x3F, 
    0xF8, 0xC3, 0x1F,
    // D
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x1F, 0x00, 0xF8, 
    0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x7F, 0xFC, 0xFF, 0x3F, 0xF8, 0xFF, 0x1F, 
    0x00, 0x00, 0x00,
    // E
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0x0F, 0x3C, 0xF0, 0x0F, 0x3C, 0xF0, 0x0F, 0x3C, 0xF0, 0x0F, 0x3C, 0xF0, 
    0x0F, 0x3C, 0xF0, 0x0F, 0x3C, 0xF0, 0x0F, 0x3C, 0xF0, 0x0F, 0x00, 0xF0, 
    0x0F, 0x00, 0xF0,
    // F
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0x0F, 0x3C, 0x00, 0x0F, 0x3C, 0x00, 0x0F, 0x3C, 0x00, 0x0F, 0x3C, 0x00, 
    0x0F, 0x3C, 0x00, 0x0F, 0x3C, 0x00, 0x0F, 0x3C, 0x00, 0x0F, 0x00, 0x00, 
    0x0F, 0x00, 0x00,
    // G
    0xF8, 0xFF, 0x1F, 0xFC, 0xFF, 0x3F, 0xFE, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 
    0x1F, 0x00, 0xF8, 0x0F, 0x00, 0xF0, 0x0F, 0x3C, 0xF0, 0x0F, 0x3C, 0xF0, 
    0x0F, 0x3C, 0xF0, 0x0F, 0xFC, 0xFF, 0x0F, 0xFC, 0xFF, 0x0F, 0xFC, 0xFF, 
    0x0F, 0xFC, 0xFF,
};

const unsigned char diesis_font[] = {
    10, 10, 0, 35, 35,
    0xCC, 0x00, 0xCC, 0x00, 0xFF, 0x03, 0xFF, 0x03, 0xCC, 0x00, 0xCC, 0x00, 
    0xFF, 0x03, 0xFF, 0x03, 0xCC, 0x00, 0xCC, 0x00,
  };

const unsigned char octave_font[] = {
    12, 11, 0, 47, 57,
    // -1, referenced by character / in ASCII
    0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x01, 
    0x0E, 0x00, 0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F,
    // 0
    0xFE, 0x07, 0xFE, 0x07, 0xFF, 0x0F, 0xFF, 0x0F, 0xE7, 0x0E, 0xE7, 0x0E, 
    0x77, 0x0E, 0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0xFE, 0x07,
    // 1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0xFF, 0x0F, 0xFF, 0x0F, 
    0xFF, 0x0F, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // 2
    0x00, 0x00, 0x87, 0x0F, 0xE7, 0x0F, 0xE7, 0x0F, 0xE7, 0x0F, 0x67, 0x0E, 
    0x7F, 0x0E, 0x7F, 0x0E, 0x7F, 0x0E, 0x1E, 0x0E, 0x00, 0x00,
    // 3
    0x00, 0x00, 0x07, 0x0E, 0x67, 0x0E, 0x67, 0x0E, 0x67, 0x0E, 0x67, 0x0E, 
    0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0x9E, 0x07, 0x00, 0x00,
    // 4
    0x7F, 0x00, 0x7F, 0x00, 0x7F, 0x00, 0x7F, 0x00, 0x60, 0x00, 0x60, 0x00, 
    0x60, 0x00, 0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F,
    // 5
    0x00, 0x00, 0x1F, 0x0E, 0x7F, 0x0E, 0x7F, 0x0E, 0x7F, 0x0E, 0x67, 0x0E, 
    0xE7, 0x0F, 0xE7, 0x0F, 0xE7, 0x0F, 0x87, 0x07, 0x00, 0x00,
    // 6
    0xFE, 0x07, 0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0x77, 0x0E, 0x77, 0x0E, 
    0x77, 0x0E, 0xF7, 0x0F, 0xF7, 0x0F, 0xE0, 0x07, 0xE0, 0x07,
    // 7
    0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x87, 0x0F, 0xF7, 0x0F, 0xF7, 0x0F, 
    0xFF, 0x0F, 0x7F, 0x00, 0x0F, 0x00, 0x0F, 0x00, 0x00, 0x00,
    // 8
    0x9E, 0x07, 0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0x67, 0x0E, 0x67, 0x0E, 
    0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0x9E, 0x07, 0x00, 0x00,
    // 9
    0x7E, 0x00, 0xFF, 0x0E, 0xFF, 0x0E, 0xFF, 0x0E, 0xE7, 0x0E, 0xE7, 0x0E, 
    0xE7, 0x0E, 0xFF, 0x0F, 0xFF, 0x0F, 0xFE, 0x07, 0xFE, 0x07,
    // 10
    0x0E, 0x00, 0xFF, 0x0F, 0xFF, 0x0F, 0x00, 0x00, 0xFE, 0x07, 0xFF, 0x0F, 
    0xFF, 0x0F, 0x03, 0x0C, 0xFF, 0x0F, 0xFF, 0x0F, 0xFE, 0x07,
};

#endif