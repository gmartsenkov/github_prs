#include <string.h>
#include "display.h"

char* display_row_text(DisplayRow *dr)
{
    unsigned int text_len = strlen(dr->text);
    dr->text + (dr->scroll_position % text_len);
}

void display_row_scroll(DisplayRow *dr) 
{
    dr->scroll_position++;
}