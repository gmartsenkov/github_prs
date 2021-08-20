#include <string.h>
#include "display.h"

char* display_row_text(DisplayRow *dr)
{
    int text_len = strlen(dr->text);

    for (int i = 0; i < DISPLAY_CHARACTER_SIZE; i++)
    {
        dr->display[i] = dr->text[dr->scroll_position + i];
    }

    dr->display[16] = NULL;
    return dr->display;
}

void display_row_scroll(DisplayRow *dr) 
{
    int text_len = strlen(dr->text);
    if(text_len <= 16)
        return;

    if(dr->scroll_position <= text_len)
    {
        dr->scroll_position++;
    }

    if(dr->scroll_position == text_len)
    {
        dr->scroll_position = 0;
    }
}