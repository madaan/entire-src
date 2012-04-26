//sg
#include<X11/Xlib.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void startListeningToMouse(Window  win,Display * dp)
{
int x,y;
XEvent xe;
GC gc;
XColor oc;
gc=XCreateGC(dp,win,NULL,NULL);
XSelectInput(dp,win,PointerMotionMask|KeyPressMask);

//Working With ColorMaps
Colormap cm=DefaultColormap(dp,DefaultScreen(dp));

while(1)
{
XNextEvent(dp,&xe);
switch(xe.type)
{
case MotionNotify:
x=xe.xbutton.x;
y=xe.xbutton.y;
oc.red=x*x;
oc.green=y*y;
oc.blue=x*y+y*x+x+y;
XAllocColor(dp,cm,&oc);

XSetForeground(dp,gc,oc.pixel);
XDrawArc(dp,win,gc,x,y,350,350,0,314);
printf("%d,%d\n",x,y);
break;
case KeyPress:
{
KeySym ks=XKeycodeToKeysym(dp,xe.xkey.keycode,0);
char *ch=XKeysymToString(ks);
XDrawString(dp,win,gc,x,y,ch,strlen(ch));
}
break;
default:
break;
}
}
}
main()
{
Display * dp;
int screen_height;
int screen_width;
int screen_number;
char * ch;
Window win;
ch=getenv("DISPLAY");
dp=XOpenDisplay(ch);
screen_number=DefaultScreen(dp);
screen_height=DisplayWidth(dp,screen_number);
screen_width=DisplayWidth(dp,screen_number);

printf("%d-%d-%d",screen_number,screen_height,screen_width);
win=XCreateSimpleWindow(dp,
			RootWindow(dp,screen_number),
			600,450,
			(screen_height/2),(screen_width/4),10,
			WhitePixel(dp,screen_number),WhitePixel(dp,screen_number));
XMapWindow(dp,win);
XSync(dp,0);
startListeningToMouse(win,dp);
}

