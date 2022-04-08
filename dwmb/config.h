static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {"", SCRIPT("bat.sh"), 5, 0},
    {"", SCRIPT("vol.sh"), 0, 7},
    {"", SCRIPT("luz.sh"), 0, 8},
    // {"", SCRIPT("cpu.sh"), 10, 0},
    // {"", SCRIPT("space.sh"), 10, 0},
    {"", SCRIPT("wifi.sh"), 15, 8},
    {"", SCRIPT("date.sh"), 60, 0}};

static char delim[] = "\0";
static unsigned int delimLen = 1;
