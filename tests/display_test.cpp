extern "C" 
{ 
    #include "display.h" 
}
#include <gtest/gtest.h>

static char* DisplayRowTest[] = {
    "A really long st",
    " really long str",
    "really long stri",
    "eally long strin",
    "ally long string",
    "lly long string ",
};

TEST(DisplayRow, display_row_text)
{
    char *text = "A really long string";
    DisplayRow dr = {0, text};

    for(int i = 0; i < 6; i++) {
        EXPECT_STREQ(display_row_text(&dr), DisplayRowTest[i]);
        display_row_scroll(&dr);
    }
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}