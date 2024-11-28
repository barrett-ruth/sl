/* See LICENSE file for copyright and license details. */
#include <stdlib.h>
#include <string.h>

/* Default settings; can be overriden by command line. */

static int topbar = 0; /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {"Gravitica Mono:size=14"};
static const char *prompt =
    NULL; /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2];

__attribute__((constructor)) void theme() {
  const char *theme = getenv("THEME");

  if (theme && strcmp(theme, "gruvbox") == 0) {
    /* Gruvbox theme */
    colors[SchemeNorm][0] = "#d4be98"; /* fg */
    colors[SchemeNorm][1] = "#282828"; /* bg */

    colors[SchemeSel][0] = "#282828"; /* fg */
    colors[SchemeSel][1] = "#a89984"; /* bg */

    colors[SchemeOut][0] = "#282828"; /* fg */
    colors[SchemeOut][1] = "#a89984"; /* bg */
  } else {
    colors[SchemeNorm][0] = "#000000"; /* fg */
    colors[SchemeNorm][1] = "#ffffff"; /* bg */

    colors[SchemeSel][0] = "#ffffff"; /* fg */
    colors[SchemeSel][1] = "#000000"; /* bg */

    colors[SchemeOut][0] = "#ffffff"; /* fg */
    colors[SchemeOut][1] = "#000000"; /* bg */
  }
}
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
