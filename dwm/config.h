/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx = 5; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const int showbar = 0;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */
static const char *fonts[] = {"monospace:size=14"};
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {"#d4be98", "#282828", "#282828"},
    [SchemeSel] = {"#282828", "#a89984", "#a89984"},
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

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
    /* modifier                     key        function        argument */
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_c, spawn, SHCMD("chromium")},
    {MODKEY, XK_space, spawn, SHCMD("dmenu_run")},
    {MODKEY, XK_Return, spawn, SHCMD("st")},

    /* Scripts */
    {SCRIPT, XK_b, spawn, SHCMD("doc book epub Books")},
    {SCRIPT, XK_c, spawn, SHCMD("clipmenu")},
    {SCRIPT, XK_d, spawn, SHCMD("doc tb pdf Documents")},
    {SCRIPT, XK_r, spawn, SHCMD("rbt")},
    {SCRIPT, XK_s, spawn, SHCMD("sdn")},
    {SCRIPT, XK_m, spawn, SHCMD("mus")},
    {SCRIPT, XK_p, spawn, SHCMD("mus prev")},
    {SCRIPT, XK_n, spawn, SHCMD("mus next")},
    {SCRIPT, XK_t, spawn, SHCMD("mus toggle")},
    {SCRIPT, XK_w, spawn, SHCMD("doas systemctl restart iwd")},
    {SCRIPT, XK_x, spawn, SHCMD("smon; sbg")},

    /* Window altering */
    {MODKEY, XK_a, focusstack, {.i = -1}},
    {MODKEY, XK_f, focusstack, {.i = +1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_o, incnmaster, {.i = -1}},
    {MODKEY, XK_u, movestack, {.i = -1}},
    {MODKEY, XK_d, movestack, {.i = +1}},
    {MODKEYS, XK_b, toggleborders, {0}},
    {MODKEYS, XK_Return, zoom, {0}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Tab, view, {0}},

    /* Multiple Monitors */
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEYS, XK_comma, tagmon, {.i = -1}},
    {MODKEYS, XK_period, tagmon, {.i = +1}},
    {MODKEYC, XK_comma, tagfocusmon, {.i = -1}},
    {MODKEYC, XK_period, tagfocusmon, {.i = +1}},

    /* Quitting */
    {MODKEY, XK_q, killclient, {0}},
    {MODKEYS, XK_q, quit, {0}},

    /* Fn Keys */
    {0, XF86XK_MonBrightnessUp, spawn, SHCMD("luz up")},
    {0, XF86XK_MonBrightnessDown, spawn, SHCMD("luz down")},
    {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("vol up")},
    {0, XF86XK_AudioLowerVolume, spawn, SHCMD("vol down")},
    {0, XF86XK_AudioMute, spawn, SHCMD("vol mute")},
    {0, XF86XK_AudioPlay, spawn, SHCMD("vol toggle")},

    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8)

    /* Layouts */
    {MODKEYS, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEYS, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEYS, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEYS, XK_space, togglefloating, {0}},
};
