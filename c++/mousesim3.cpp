//sg
#include<X11/Xlib.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
using namespace std;
int main()
{
    int x,y,sn;
    char * ch;
    timeval * tv;
    Display * dp;
    int i=4;
    XEvent xe;
    Status s;
    long mask=PointerMotionMask;
    ch=getenv("DISPLAY");
    dp=XOpenDisplay(ch);
    freopen("stdin","r",stdin);
    if(dp==NULL)
    {   printf("ERROR");
        exit(1);
    }
    sn=DefaultScreen(dp);
    xe.type=MotionNotify;
    Window  win;
    int a;
    xe.xbutton.display =dp;
    xe.xbutton.window =XGetInputFocus(dp,&win,&a);
    xe.xbutton.root = RootWindow(dp,sn);
    xe.xbutton.subwindow = None;
    xe.xbutton.same_screen =1;
    XGetInputFocus(dp,&win,&a);
    while(i>0)
    {
//ct=time(NULL);
//cout<<ct;
        cin>>x>>y;
//xe.xbutton.x=x;
//xe.xbutton.y=y;
        gettimeofday(tv, NULL);
        xe.xbutton.time =(tv->tv_sec)*1000;
        xe.xbutton.x = x;
        xe.xbutton.y = y;
        xe.xbutton.x_root = x;
        xe.xbutton.y_root = y;
        s=XSendEvent(dp,win,true,mask,&xe);
        cout<<s;
        i--;
    }
    return 0;
}
