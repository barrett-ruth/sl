static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {"", SCRIPT("bat.sh"), 5, 0},
    {"", SCRIPT("vol.sh"), 0, 5},
    {"", SCRIPT("luz.sh"), 0, 7},
    {"", SCRIPT("wifi.sh"), 5, 10},
    {"", SCRIPT("date.sh"), 5, 0}};

static char delim[] = "\0";
static unsigned int delimLen = 1;
