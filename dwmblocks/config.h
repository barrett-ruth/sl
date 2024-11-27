static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {"", SCRIPT("vol.sh"), 0, 5},
    {"", SCRIPT("bat.sh"), 5, 0},
    {"", SCRIPT("wifi.sh"), 5, 0},
    {"", SCRIPT("date.sh"), 5, 0}};

static char delim[] = "\0";
static unsigned int delimLen = 1;
