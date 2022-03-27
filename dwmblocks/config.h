// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {SCRIPT("bat.sh"), 5, 0},
    {SCRIPT("light.sh"), 0, 8},
    {SCRIPT("cpu.sh"), 10, 0},
    {SCRIPT("space.sh"), 10, 0},
    {SCRIPT("wifi.sh"), 15, 8},
    {SCRIPT("vol.sh"), 0, 7},
    {SCRIPT("date.sh"), 60, 0}};

// sets delimeter between status commands. NULL character ('\0') means no
// delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
