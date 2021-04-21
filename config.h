/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const char *fonts[]          = { "wqy-zenhei:size=11" };
static const char dmenufont[]       = "Source Code Pro:size=11";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#ffffff";
static const char col_gray4[]       = "#282828";
static const char col_border[]      = "#00AAAA";
static const char col_cyan[]        = "#a1a1a1";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_border  },
	[SchemeHid]  = { col_cyan,  col_gray1, col_border  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Firefox",  NULL,       NULL,       0,			      1,           -1 },
	{ "Thunar",   NULL,       NULL,       0,						1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "平铺",      tile },    /* first entry is default */
	{ "浮动",      NULL },    /* no layout function means floating behavior */
	{ "单页",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };

static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };
static const char *termcmd[]  = { "st", NULL };

static const char *thunarcmd[]  = { "thunar", NULL };
/*自定义快捷*/
static const char *browsercmd[]  = { "firefox", NULL };
static const char *flameshot[] = { "flameshot", "gui", "-p", "/home/rewrite/Desktop/Screenshot", NULL };
static const char *lock[] = { "slock", NULL };
/*音量控制*/
static const char *volup[]   = { "vol-up.sh",  NULL };
static const char *voldown[] = { "vol-down.sh",  NULL };
static const char *volmute[] = { "vol-toggle.sh",  NULL };
/*亮度控制*/
static const char *lightup[] = { "light-up.sh",  NULL };
static const char *lightdown[] = { "light-down.sh",  NULL };
/*壁纸切换*/
static const char *bgnext[] = { "pkill", "sleep", NULL };
/*cmus控制*/
static const char *mplay[] = { "cmus_control.sh", "play", NULL };
static const char *mquit[] = { "cmus_control.sh", "quit", NULL };
static const char *mnext[] = { "cmus-remote", "--next", NULL };
static const char *mprev[] = { "cmus-remote", "--prev", NULL };
static const char *mpause[] = { "cmus-remote", "--pause", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	/*壁纸切换*/
	{ MODKEY|Mod4Mask,							XK_n,									  spawn,          {.v = bgnext } },
	/*dmenu*/                                           
	{ ShiftMask,                    XK_space,							  spawn,          {.v = dmenucmd } },
	/*终端*/                                            
	{ MODKEY,											  XK_Return,						  spawn,          {.v = termcmd } },
	/*浮动终端*/                                        
	{ MODKEY,                       XK_grave,							  togglescratch,  {.v = scratchpadcmd } },
	/*thunar*/
	{ MODKEY,              		      XK_c,                   spawn,          {.v = thunarcmd } },
	/*浏览器*/
	{ MODKEY,              		      XK_b,                   spawn,          {.v = browsercmd } },
	/*锁屏*/
	{ MODKEY|Mod4Mask,              XK_l,                   spawn,          {.v = lock } },
	/*截图*/
	{ ControlMask|Mod1Mask,		      XK_a,									  spawn,	        {.v = flameshot } },
	/*cmus控制*/
	{ ControlMask|Mod4Mask,		      XK_p,									  spawn,	        {.v = mplay } },
	{ ControlMask|Mod4Mask,		      XK_space,								spawn,	        {.v = mpause } },
	{ ControlMask|Mod4Mask,		      XK_n,									  spawn,	        {.v = mnext } },
	{ ControlMask|Mod4Mask,		      XK_u,									  spawn,	        {.v = mprev } },
	{ ControlMask|Mod4Mask,		      XK_q,									  spawn,	        {.v = mquit } },
	/*音量控制*/
	{ MODKEY,                       XK_bracketleft,         spawn,          {.v = voldown } },
	{ MODKEY,                       XK_backslash,           spawn,          {.v = volmute } },
	{ MODKEY,                       XK_bracketright,        spawn,          {.v = volup   } },
	/*亮度控制*/
	{ Mod4Mask,                     XK_bracketleft,         spawn,          {.v = lightdown } },
	{ Mod4Mask,						  				XK_bracketright,        spawn,          {.v = lightup   } },
	/*窗口隐藏*/                                              
	{ Mod4Mask,                     XK_h,		                hidewin,        {0} },
	/*窗口显示*/                                              
	{ MODKEY|ControlMask,           XK_h,		                restorewin,     {0} },
	/*状态栏显示隐藏*/
	{ Mod4Mask,                     XK_b,		                togglebar,      {0} },
	/*平铺窗口位置调整*/                                      
	{ ShiftMask|MODKEY,		      		XK_j,		                rotatestack,    {.i = +1 } },
	{ ShiftMask|MODKEY,			      	XK_k,		                rotatestack,    {.i = -1 } },
	/*更改活动窗口*/                                          
	{ Mod4Mask,                     XK_j,		                focusstack,     {.i = +1 } },
	{ Mod4Mask,                     XK_k,		                focusstack,     {.i = -1 } },
	/*更改平铺排列方式*/                                      
	{ MODKEY,                       XK_n,		                incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_m,		                incnmaster,     {.i = -1 } },
	/*平铺窗口大小调整*/                                      
	{ MODKEY,                       XK_h,		                setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,		                setmfact,       {.f = +0.05} },
	/*互换窗口位置*/                                     
	{ Mod4Mask,                     XK_Return,	            zoom,           {0} },
	/*将所有标签页中的窗口显示到当前页*/                  
	{ MODKEY,                       XK_Tab,                 view,           {.ui = ~0 } },
	/*恢复原样*/                                          
	{ MODKEY|ShiftMask,             XK_Tab,                 view,           {0} },
	/*关闭窗口*/                                         
	{ MODKEY,		                    XK_q,		                killclient,     {0} },
	/*设置布局模式*/                                     
	/*设为平铺模式*/                                     
	{ Mod4Mask,                     XK_p,                  setlayout,      {.v = &layouts[0]} },
	/*设为浮动模式*/                                     
	{ Mod4Mask,                     XK_f,                  setlayout,      {.v = &layouts[1]} },
	/*设为单页模式*/                                     
	{ Mod4Mask,                     XK_m,                  setlayout,      {.v = &layouts[2]} },
	/*切换布局模式*/                                     
	{ MODKEY,                       XK_space,              setlayout,      {0} },
	/*窗口全屏*/
	{ MODKEY,												XK_f,										fullscreen,     {0} },
	/*切换浮动*/                                         
	{ MODKEY|ShiftMask,             XK_space,	             togglefloating, {0} },
	/*显示所有tag*/
	{ MODKEY|ShiftMask,             XK_0,		               tag,            {.ui = ~0 } },
	/*切换聚焦显示器*/
	{ MODKEY,                       XK_comma,	             focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,	           focusmon,       {.i = +1 } },
	/*将内容转移到其他显示器*/
	{ MODKEY|ShiftMask,             XK_comma,	             tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,	           tagmon,         {.i = +1 } },
	/*切换相邻标签*/
	{ Mod4Mask,                    	XK_1,                  viewtoleft,     {0} },
	{ Mod4Mask,                    	XK_2,                  viewtoright,    {0} },
	/*将窗口移动到相邻标签*/
	{ MODKEY|ShiftMask,             XK_Left,               tagtoleft,      {0} },
	{ MODKEY|ShiftMask,             XK_Right,              tagtoright,     {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ControlMask,           XK_q,							     quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

