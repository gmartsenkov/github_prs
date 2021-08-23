#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "lcd1602.h"
#include "display.h"

static volatile int keep_running = 1;

void int_handler(int i)
{
    keep_running = 0;
}

int main() {
    int rc;

    rc = lcd1602Init(1, 0x27);

    if(rc)
    {
        printf("Initialization error\n");
        return 1;
    }

    DisplayRow dr;
    display_row_init(&dr, "A really long string");


    lcd1602Control(1,0,1);

    signal(SIGINT, int_handler);

    while(keep_running) {
        lcd1602SetCursor(0, 0);
        lcd1602WriteString(display_row_text(&dr));

        display_row_scroll(&dr);
        usleep(500 * 1000);
    }

    lcd1602Clear();
    lcd1602Shutdown();
}