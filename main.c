#include <stdio.h>
#include <lcd1602.h>

int main() {
    int rc;

    rc = lcd1602Init(1, 0x27);

    if(rc)
    {
        printf("Initialization error\n");
        return 1;
    }

    lcd1602WriteString("Hello");
    lcd1602SetCursor(0, 1);
    lcd1602WriteString("World");
    lcd1602Control(1,0,1);

    getchar();
    lcd1602Shutdown();
}