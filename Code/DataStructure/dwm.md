# vars
```
static const char broken[] = "broken";
static char stext[256];
static int screen;
static int sw, sh;      /* X display screen geometry width, height */
static int bh, blw = 0; /* bar geometry */
static int lrpad;       /* sum of left and right padding for text */
static int (*xerrorxlib)(Display*, XErrorEvent*);
static unsigned int numlockmask = 0;
static void (*handler[LASTEvent])(XEvent*) = {
  [ButtonPress] = buttonpress,
  [ClientMessage] = clientmessage,
  [ConfigureRequest] = configurerequest,
  [ConfigureNotify] = configurenotify,
  [DestroyNotify] = destroynotify,
  [EnterNotify] = enternotify,
  [Expose] = expose,
  [FocusIn] = focusin,
  [KeyPress] = keypress,
  [MappingNotify] = mappingnotify,
  [MapRequest] = maprequest,
  [MotionNotify] = motionnotify,
  [PropertyNotify] = propertynotify,
  [UnmapNotify] = unmapnotify
};
static Atom wmatom[WMLast], netatom[NetLast];
static int running = 1;
static Cur* cursor[CurLast];
static Clr** scheme;
static Display* dpy;
static Drw* drw;
static Monitor *mons, *selmon;
static Window root, wmcheckwin;
```

# enums
``` cpp
/* enums */
enum { CurNormal,
  CurResize,
  CurMove,
  CurLast }; /* cursor */
enum { SchemeNorm,
  SchemeSel }; /* color schemes */
enum { NetSupported,
  NetWMName,
  NetWMState,
  NetWMCheck,
  NetWMFullscreen,
  NetActiveWindow,
  NetWMWindowType,
  NetWMWindowTypeDialog,
  NetClientList,
  NetLast }; /* EWMH atoms */
enum { WMProtocols,
  WMDelete,
  WMState,
  WMTakeFocus,
  WMLast }; /* default atoms */
enum { ClkTagBar,
  ClkLtSymbol,
  ClkStatusText,
  ClkWinTitle,
  ClkClientWin,
  ClkRootWin,
  ClkLast }; /* clicks */
```
# function declarations
``` cpp
- [ ] static void applyrules(Client* c);
- [ ] static int applysizehints(Client* c, int* x, int* y, int* w, int* h, int interact);
- [ ] static void arrange(Monitor* m);
- [ ] static void arrangemon(Monitor* m);
- [ ] static void attach(Client* c);
- [ ] static void attachstack(Client* c);
- [ ] static void buttonpress(XEvent* e);
- [ ] static void checkotherwm(void);
- [ ] static void cleanup(void);
- [ ] static void cleanupmon(Monitor* mon);
- [ ] static void clientmessage(XEvent* e);
- [ ] static void configure(Client* c);
- [ ] static void configurenotify(XEvent* e);
- [ ] static void configurerequest(XEvent* e);
- [ ] static Monitor* createmon(void);
- [ ] static void destroynotify(XEvent* e);
- [ ] static void detach(Client* c);
- [ ] static void detachstack(Client* c);
- [ ] static Monitor* dirtomon(int dir);
- [ ] static void drawbar(Monitor* m);
- [ ] static void drawbars(void);
- [ ] static void enternotify(XEvent* e);
- [ ] static void expose(XEvent* e);
- [ ] static void focus(Client* c);
- [ ] static void focusin(XEvent* e);
- [ ] static void focusmon(const Arg* arg);
- [ ] static void focusstack(const Arg* arg);
- [ ] static Atom getatomprop(Client* c, Atom prop);
- [ ] static int getrootptr(int* x, int* y);
- [ ] static long getstate(Window w);
- [ ] static int gettextprop(Window w, Atom atom, char* text, unsigned int size);
- [ ] static void grabbuttons(Client* c, int focused);
- [ ] static void grabkeys(void);
- [ ] static void incnmaster(const Arg* arg);
- [ ] static void keypress(XEvent* e);
- [ ] static void killclient(const Arg* arg);
- [ ] static void manage(Window w, XWindowAttributes* wa);
- [ ] static void mappingnotify(XEvent* e);
- [ ] static void maprequest(XEvent* e);
- [ ] static void monocle(Monitor* m);
- [ ] static void motionnotify(XEvent* e);
- [ ] static void movemouse(const Arg* arg);
- [ ] static Client* nexttiled(Client* c);
- [ ] static void pop(Client*);
- [ ] static void propertynotify(XEvent* e);
- [ ] static void quit(const Arg* arg);
- [ ] static Monitor* recttomon(int x, int y, int w, int h);
- [ ] static void resize(Client* c, int x, int y, int w, int h, int interact);
- [ ] static void resizeclient(Client* c, int x, int y, int w, int h);
- [ ] static void resizemouse(const Arg* arg);
- [ ] static void restack(Monitor* m);
- [ ] static void run(void);
- [ ] static void scan(void);
- [ ] static int sendevent(Client* c, Atom proto);
- [ ] static void sendmon(Client* c, Monitor* m);
- [ ] static void setclientstate(Client* c, long state);
- [ ] static void setfocus(Client* c);
- [ ] static void setfullscreen(Client* c, int fullscreen);
- [ ] static void setlayout(const Arg* arg);
- [ ] static void setmfact(const Arg* arg);
- [ ] static void setup(void);
- [ ] static void seturgent(Client* c, int urg);
- [ ] static void showhide(Client* c);
- [ ] static void sigchld(int unused);
- [ ] static void spawn(const Arg* arg);
- [ ] static void tag(const Arg* arg);
- [ ] static void tagmon(const Arg* arg);
- [ ] static void tile(Monitor*);
- [ ] static void togglebar(const Arg* arg);
- [ ] static void togglefloating(const Arg* arg);
- [ ] static void toggletag(const Arg* arg);
- [ ] static void toggleview(const Arg* arg);
- [ ] static void unfocus(Client* c, int setfocus);
- [ ] static void unmanage(Client* c, int destroyed);
- [ ] static void unmapnotify(XEvent* e);
- [ ] static void updatebarpos(Monitor* m);
- [ ] static void updatebars(void);
- [ ] static void updateclientlist(void);
- [ ] static int updategeom(void);
- [ ] static void updatenumlockmask(void);
- [ ] static void updatesizehints(Client* c);
- [ ] static void updatestatus(void);
- [ ] static void updatetitle(Client* c);
- [ ] static void updatewindowtype(Client* c);
- [ ] static void updatewmhints(Client* c);
- [ ] static void view(const Arg* arg);
- [ ] static Client* wintoclient(Window w);
- [ ] static Monitor* wintomon(Window w);
- [ ] static int xerror(Display* dpy, XErrorEvent* ee);
- [ ] static int xerrordummy(Display* dpy, XErrorEvent* ee);
- [ ] static int xerrorstart(Display* dpy, XErrorEvent* ee);
- [ ] static void zoom(const Arg* arg);
```
# Structs

## Arg def
union
  - int i;
  - unsigned int ui;
  - float f;
  - const void* v;
union means one of

## Button
  unsigned int click;
  unsigned int mask;
  unsigned int button;
  void (*func)(const Arg* arg);
  const Arg arg;

## Client
  - name
  - float mina, maxa;
  - int x, y, w, h;
  - int oldx, oldy, oldw, oldh;
  - int basew, baseh, incw, inch, maxw, maxh, minw, minh;
  - int bw, oldbw;
  - unsigned int tags;
      tag of a window(like st)
  - int isfixed, isfloating, isurgent, neverfocus, oldstate, isfullscreen;
      some features of a window
  - Client* next;
      next window
  - Client* snext;
      prev window
  - Monitor* mon;
  - Window win;

## Keys
  - unsigned int mod;
  - KeySym keysym;
  - void (*func)(const Arg*);
  - const Arg arg;

## Layout
  - const char* symbol;
  - void (*arrange)(Monitor*);

## Monitor
  the main X
  - char ltsymbol[16];
  - float mfact;
  - int nmaster;
  - int num;
  - int by;             /* bar geometry */
  - int mx, my, mw, mh; /* screen size */
  - int wx, wy, ww, wh; /* window area  */
  - unsigned int seltags;
  - unsigned int sellt;
  - unsigned int tagset[2];
  - int showbar;
  - int topbar;
  - Client* clients;
  - Client* sel;
  - Client* stack;
  - Monitor* next;
  - Window barwin;
  - const Layout* lt[2];

## Rule
  - const char* class;
  - const char* instance;
  - const char* title;
  - unsigned int tags;
  - int isfloating;
  - int monitor;


