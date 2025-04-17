#include <libgen.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char background_image[256];

/* user and group to drop privileges to */
static const char *user;
__attribute__((constructor)) void username() {
  struct passwd *pw = getpwuid(getuid());
  user = pw->pw_name;

  snprintf(background_image, sizeof(background_image),
           "/home/%s/dev/sl/slock/lock.jpg", user);
}

static const char *group = "wheel";

static const char *colorname[NUMCOLS] = {
    [INIT] = "black",     /* after initialization */
    [INPUT] = "#005577",  /* during input */
    [FAILED] = "#CC3333", /* wrong password */
};

static const int failonclear = 1;
