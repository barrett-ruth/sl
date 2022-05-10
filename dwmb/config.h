static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {"", SCRIPT("bat.sh"), 5, 0},
    {"", SCRIPT("block1.sh"), 0, 0},
    {"", SCRIPT("wifi.sh"), 5, 7},
    {"", SCRIPT("block2.sh"), 0, 0},
    {"", SCRIPT("date.sh"), 5, 0}};

static char delim[] = "\0";
static unsigned int delimLen = 1;
