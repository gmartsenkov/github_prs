#include <stdint.h>

typedef struct Display {
    char row_1[16];
    char *row_1_text;
    uint8_t row_1_position;

    char row_2[16];
    char *row_2_text;
} Display;