#include <string.h>
#include <stdlib.h>
#include "display.h"

void display_row_init(DisplayRow *dr, char *text)
{
    dr->scroll_position = 0;
    dr->text = text;
    dr->text_len = strlen(text);

    if(dr->text_len < DISPLAY_CHARACTER_SIZE)
        return;

    char *new_text = (char *)calloc(dr->text_len + (DISPLAY_CHARACTER_SIZE * 2), sizeof(char));

    strncat(new_text, dr->text, dr->text_len);
    memset(&new_text[dr->text_len], ' ', DISPLAY_CHARACTER_SIZE);
    strncat(new_text, dr->text, DISPLAY_CHARACTER_SIZE);

    dr->text = new_text;
    dr->text_len = strlen(new_text);
}

void display_row_free(DisplayRow *dr)
{
    free(dr->text);

    dr->scroll_position = 0;
    dr->text_len = 0;
    dr->text = NULL;
}

char* display_row_text(DisplayRow *dr)
{
    return &dr->text[dr->scroll_position];
}

void display_row_scroll(DisplayRow *dr) 
{
    if(dr->text_len < DISPLAY_CHARACTER_SIZE)
        return;

    int reset_position = dr->text_len - DISPLAY_CHARACTER_SIZE;

    if(dr->scroll_position == reset_position - 1)
    {
        dr->scroll_position=0;
        return;
    }

    dr->scroll_position++;
}