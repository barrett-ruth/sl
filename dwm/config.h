/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>
#include <stdlib.h>
#include <string.h>

#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx = 5; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const int showbar = 0;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */
static const char *fonts[] = {"Gravitica Mono:size=15"};
static const char *colors[2][3];

__attribute__((constructor)) void theme() {
  const char *theme = getenv("THEME");

  if (theme && strcmp(theme, "gruvbox") == 0) {
    colors[SchemeNorm][0] = "#d4be98"; /* fg */
    colors[SchemeNorm][1] = "#282828"; /* bg */
    colors[SchemeNorm][2] = "#282828"; /* border */

    colors[SchemeSel][0] = "#282828"; /* fg */
    colors[SchemeSel][1] = "#a89984"; /* bg */
    colors[SchemeSel][2] = "#a89984"; /* border */
  } else {
    colors[SchemeNorm][0] = "#ffffff"; /* fg */
    colors[SchemeNorm][1] = "#000000"; /* bg */
    colors[SchemeNorm][2] = "#000000"; /* border */

    colors[SchemeSel][0] = "#000000"; /* fg */
    colors[SchemeSel][1] = "#ffffff"; /* bg */
    colors[SchemeSel][2] = "#ffffff"; /* border */
  }
}

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Chromium", NULL, NULL, 1 << 1, 0, -1},
    {"sioyek", NULL, NULL, 1 << 2, 0, -1},
    {"Slack", NULL, NULL, 1 << 3, 0, -1},
    {"discord", NULL, NULL, 1 << 4, 0, -1},
};

/* layout(s) */
static const float mfact = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;   /* number of clients in master area */
static const int resizehints =
    0; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"||", tile},  /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"|\\/|", monocle},
};

/* key definitions */
#define MODKEY Mod1Mask
#define MODKEYS MODKEY | ShiftMask
#define MODKEYC MODKEY | ControlMask
#define SCRIPT Mod3Mask

#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, tagview, {.ui = 1 << TAG}},                  \
      {MODKEYS, KEY, tag, {.ui = 1 << TAG}},                                   \
      {MODKEYS | ControlMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

static Key keys[] = {
    {MODKEYS, XK_b, toggleborders, {0}},
    {MODKEYS, XK_c, spawn, SHCMD("chromium")},
    {MODKEYC, XK_c, spawn, SHCMD("chromium --force-device-scale-factor=1.5")},
    {MODKEYS, XK_s, spawn, SHCMD("slack")},
    {MODKEYS, XK_Return, spawn, SHCMD("ghostty")},
    {MODKEY, XK_space, spawn, SHCMD("dmenu_run")},

    {0, XF86XK_MonBrightnessUp, spawn, SHCMD("brightnessctl set 10%+")},
    {0, XF86XK_MonBrightnessDown, spawn, SHCMD("brightnessctl set 10%-")},
    {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("vol up")},
    {0, XF86XK_AudioLowerVolume, spawn, SHCMD("vol down")},
    {0, XF86XK_AudioMute, spawn, SHCMD("vol mute")},
    {0, XF86XK_Favorites, spawn, SHCMD("cycle-brightness")},
    {0, XF86XK_Display, spawn, SHCMD("smon && sbg")},

    {SCRIPT, XK_a, spawn, SHCMD("set-speaker")},
    {SCRIPT, XK_c, spawn, SHCMD("clipmenu")},
    {SCRIPT, XK_d, spawn, SHCMD("doc")},
    {SCRIPT, XK_k, spawn, SHCMD("skb toggle")},
    {SCRIPT, XK_r, spawn, SHCMD("rbt")},
    {SCRIPT, XK_s, spawn, SHCMD("sss")},
    {SCRIPT, XK_t, spawn, SHCMD("ocr")},

    {MODKEY, XK_a, focusstack, {.i = -1}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_f, focusstack, {.i = +1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_o, incnmaster, {.i = -1}},
    {MODKEY, XK_u, movestack, {.i = -1}},
    {MODKEY, XK_d, movestack, {.i = +1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},

    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEYS, XK_comma, tagmon, {.i = -1}},
    {MODKEYS, XK_period, tagmon, {.i = +1}},
    {MODKEYC, XK_comma, tagfocusmon, {.i = -1}},
    {MODKEYC, XK_period, tagfocusmon, {.i = +1}},

    {MODKEY, XK_q, killclient, {0}},
    {MODKEYS, XK_q, quit, {0}},
    {MODKEYS, XK_r, quit, {1}},

    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8)

    /* Layouts */
    {MODKEYS, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEYS, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEYS, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEYS, XK_space, togglefloating, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
