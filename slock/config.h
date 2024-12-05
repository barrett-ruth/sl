#include <libgen.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* user and group to drop privileges to */
static const char *user;
__attribute__((constructor)) void username() {
  user = getpwuid(getuid())->pw_name;
}
static const char *group = "wheel";

static const char *colorname[NUMCOLS] = {
    [INIT] = "black",     /* after initialization */
    [INPUT] = "#005577",  /* during input */
    [FAILED] = "#CC3333", /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* Background image path, should be available to the user above */
static const char *background_image;
static const char *image_name = "lock.jpg";
static char *path;

__attribute__((constructor)) void set_background_image() {
  const char *dir = dirname(strdup(__FILE__));
  size_t len = strlen(dir) + strlen(image_name) + 2;
  path = (char *)malloc(len);
  snprintf(path, len, "%s/%s", dir, image_name);
  background_image = path;
}
__attribute__((destructor)) void cleanup_background_image() {
  free((void *)path);
}
