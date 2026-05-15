#pragma once
#include <cstdint>

struct Cell{
    char ch = ' '; //ch displayed
    uint8_t fg = 7; // text color 7 - white
    uint8_t bg = 0; // background black
    bool bold = false;
    bool underline = false;

    bool operator==(const Cell& other) const {
        return ch == other.ch
            && fg == other.fg
            && bg == other.bg
            && bold == other.bold
            && underline == other.underline;
    };
};