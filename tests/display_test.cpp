extern "C" 
{ 
    #include "display.h" 
}
#include <gtest/gtest.h>

static char* DisplayRowTest[] = {
    "A really long string                A really long st",
    " really long string                A really long st",
    "really long string                A really long st",
    "eally long string                A really long st",
    "ally long string                A really long st",
    "lly long string                A really long st",
    "ly long string                A really long st",
    "y long string                A really long st",
    " long string                A really long st",
    "long string                A really long st",
    "ong string                A really long st",
    "ng string                A really long st",
    "g string                A really long st",
    " string                A really long st",
    "string                A really long st",
    "tring                A really long st",
    "ring                A really long st",
    "ing                A really long st",
    "ng                A really long st",
    "g                A really long st",
    "                A really long st",
    "               A really long st",
    "              A really long st",
    "             A really long st",
    "            A really long st",
    "           A really long st",
    "          A really long st",
    "         A really long st",
    "        A really long st",
    "       A really long st",
    "      A really long st",
    "     A really long st",
    "    A really long st",
    "   A really long st",
    "  A really long st",
    " A really long st",
    "A really long string                A really long st",
    " really long string                A really long st",
};

TEST(DisplayRow, display_row_text)
{
    char *text = "A really long string";
    DisplayRow dr;
    display_row_init(&dr, text);

    int tests = sizeof(DisplayRowTest) / sizeof(char*);
    for(int i = 0; i < tests; i++) {
        EXPECT_STREQ(display_row_text(&dr), DisplayRowTest[i]);
        display_row_scroll(&dr);
    }
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}