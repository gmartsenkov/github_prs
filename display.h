#include <stdint.h>

#ifndef DISPLAY_H
#define DISPLAY_H

#define DISPLAY_CHARACTER_SIZE 16
#define DISPLAY_ROW_SIZE 2

typedef struct DiplayRow {
    uint8_t scroll_position;
    char *text;
    unsigned int text_len;
} DisplayRow;

void display_row_init(DisplayRow *dr, char *text);
char* display_row_text(DisplayRow *dr);
void display_row_scroll(DisplayRow *dr);
void display_row_free(DisplayRow *dr);

typedef struct Display {
    DisplayRow rows[DISPLAY_ROW_SIZE];
} Display;

void display_init(Display *display);

#endif