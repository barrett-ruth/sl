diff --git a/config.h b/config.h
index 7765105..2746190 100644
--- a/config.h
+++ b/config.h
@@ -5,8 +5,8 @@
  *
  * font: see http://freedesktop.org/software/fontconfig/fontconfig-user.html
  */
-static char *font = "Liberation Mono:pixelsize=12:antialias=true:autohint=true";
-static int borderpx = 2;
+static char *font = "JetBrains Mono:pixelsize=18:antialias=true:autohint=true";
+static int borderpx = 0;
 
 /*
  * What program is execed by st depends of these precedence rules:
@@ -107,33 +107,25 @@ unsigned int tabspaces = 8;
 
 /* Terminal colors (16 first used in escape sequence) */
 static const char *colorname[] = {
-	/* 8 normal colors */
-	"black",
-	"red3",
-	"green3",
-	"yellow3",
-	"blue2",
-	"magenta3",
-	"cyan3",
-	"gray90",
-
-	/* 8 bright colors */
-	"gray50",
-	"red",
-	"green",
-	"yellow",
-	"#5c5cff",
-	"magenta",
-	"cyan",
-	"white",
-
-	[255] = 0,
-
-	/* more colors can be added after 255 to use with DefaultXX */
-	"#cccccc",
-	"#555555",
-	"gray90", /* default foreground colour */
-	"black", /* default background colour */
+    /* 8 normal colors */
+    [0] = "#282828", /* hard contrast: #1d2021 / soft contrast: #32302f */
+    [1] = "#ea6962", /* red     */
+    [2] = "#a9b665", /* green   */
+    [3] = "#d8a657", /* yellow  */
+    [4] = "#7daea3", /* blue    */
+    [5] = "#d3869b", /* magenta */
+    [6] = "#89b482", /* cyan    */
+    [7] = "#d4be98", /* white   */
+
+    /* 8 bright colors */
+    [8] = "#928374",  /* black   */
+    [9] = "#ef938e",  /* red     */
+    [10] = "#bbc585", /* green   */
+    [11] = "#e1bb7e", /* yellow  */
+    [12] = "#9dc2ba", /* blue    */
+    [13] = "#e1acbb", /* magenta */
+    [14] = "#a7c7a2", /* cyan    */
+    [15] = "#e2d3ba", /* white   */
 };
 
 
@@ -141,9 +133,9 @@ static const char *colorname[] = {
  * Default colors (colorname index)
  * foreground, background, cursor, reverse cursor
  */
-unsigned int defaultfg = 258;
-unsigned int defaultbg = 259;
-unsigned int defaultcs = 256;
+unsigned int defaultfg = 15;
+unsigned int defaultbg = 0;
+unsigned int defaultcs = 15;
 static unsigned int defaultrcs = 257;
 
 /*
@@ -153,7 +145,7 @@ static unsigned int defaultrcs = 257;
  * 6: Bar ("|")
  * 7: Snowman ("☃")
  */
-static unsigned int cursorshape = 2;
+static unsigned int cursorshape = 6;
 
 /*
  * Default columns and rows numbers
@@ -188,33 +180,41 @@ static uint forcemousemod = ShiftMask;
  */
 static MouseShortcut mshortcuts[] = {
 	/* mask                 button   function        argument       release */
-	{ XK_ANY_MOD,           Button2, selpaste,       {.i = 0},      1 },
-	{ ShiftMask,            Button4, ttysend,        {.s = "\033[5;2~"} },
-	{ XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"} },
-	{ ShiftMask,            Button5, ttysend,        {.s = "\033[6;2~"} },
-	{ XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"} },
+        {ShiftMask, Button4, ttysend, {.s = "\033[5;2~"}},
+        {ShiftMask, Button5, ttysend, {.s = "\033[6;2~"}},
+        {XK_ANY_MOD, Button4, kscrollup, {.i = 3}, 0},
+        {XK_ANY_MOD, Button5, kscrolldown, {.i = 3}, 0},
 };
 
 /* Internal keyboard shortcuts. */
-#define MODKEY Mod1Mask
-#define TERMMOD (ControlMask|ShiftMask)
+#define TERMMOD Mod1Mask
+#define TERMMODS TERMMOD | ShiftMask
+#define SCRIPT Mod3Mask
+
+#define SHCMD(cmd)                                                             \
+  {                                                                            \
+    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
+  }
 
 static Shortcut shortcuts[] = {
 	/* mask                 keysym          function        argument */
-	{ XK_ANY_MOD,           XK_Break,       sendbreak,      {.i =  0} },
-	{ ControlMask,          XK_Print,       toggleprinter,  {.i =  0} },
-	{ ShiftMask,            XK_Print,       printscreen,    {.i =  0} },
-	{ XK_ANY_MOD,           XK_Print,       printsel,       {.i =  0} },
-	{ TERMMOD,              XK_Prior,       zoom,           {.f = +1} },
-	{ TERMMOD,              XK_Next,        zoom,           {.f = -1} },
-	{ TERMMOD,              XK_Home,        zoomreset,      {.f =  0} },
-	{ TERMMOD,              XK_C,           clipcopy,       {.i =  0} },
-	{ TERMMOD,              XK_V,           clippaste,      {.i =  0} },
-	{ TERMMOD,              XK_Y,           selpaste,       {.i =  0} },
-	{ ShiftMask,            XK_Insert,      selpaste,       {.i =  0} },
-	{ TERMMOD,              XK_Num_Lock,    numlock,        {.i =  0} },
-	{ ShiftMask,            XK_Page_Up,     kscrollup,      {.i = -1} },
-	{ ShiftMask,            XK_Page_Down,   kscrolldown,    {.i = -1} },
+        // Copy-paste
+        {TERMMOD, XK_y, clipcopy, {.i = 0}},
+        {TERMMOD, XK_p, clippaste, {.i = 0}},
+
+        // Zoom
+        {TERMMODS, XK_H, zoom, {.f = -5}},
+        {TERMMODS, XK_L, zoom, {.f = +5}},
+
+        // Scroll
+        {TERMMOD, XK_j, kscrolldown, {.i = 9}},
+        {TERMMOD, XK_k, kscrollup, {.i = 9}},
+        {TERMMODS, XK_J, kscrolldown, {.i = 18}},
+        {TERMMODS, XK_K, kscrollup, {.i = 18}},
+
+        // Urls
+        {SCRIPT, XK_y, externalpipe, SHCMD("url copy")},
+        {SCRIPT, XK_o, externalpipe, SHCMD("url open")},
 };
 
 /*
