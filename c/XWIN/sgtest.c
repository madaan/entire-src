//sg
#include<stdio.h>
#include<X11/Xlib.h>
void startListeningToMouse(Window sgwin,Display * dp)

{
XEvent xe;
int sn=DefaultScreen(dp);
Window rw=RootWindow(dp,sn);
GC gc=XCreateGC(dp,sgwin,NULL,NULL);

XSelectInput(dp,sgwin,PointerMotionMask);
while(1)
{
XNextEvent(dp,&xe);
switch(xe.type)
{
case MotionNotify:
XDrawString(dp,sgwin,gc,xe.xbutton.x,xe.xbutton.y,"SHREE GANESH",12);
printf("%ld\n",xe.xbutton.time);
break;


}
}
}
main()
{
Display * dp;
Window sgwin;
char * ch;
int sn;
ch=getenv("DISPLAY");
dp=XOpenDisplay(ch);
if(dp==NULL)
{printf("ERROR");
exit(1);
}
sn=DefaultScreen(dp);
sgwin=XCreateSimpleWindow(dp,RootWindow(dp,sn),0,0,1300,700,1,BlackPixel(dp,sn),WhitePixel(dp,sn));
XMapWindow(dp,sgwin);
startListeningToMouse(sgwin,dp);
XFlush(dp);
sleep(4);
XCloseDisplay(dp);

}

