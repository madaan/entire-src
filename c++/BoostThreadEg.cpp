//sg
#include <boost/thread/thread.hpp>
#include <iostream>
#include<string.h>
#include<ncurses.h>
using namespace std;
boost::mutex mutex;
void runnable(int id,int x,int y,string str)
{
	
	char progressStr[100];
	char progressBar[100];
	progressBar[0]='#';
	progressBar[1]='\0';
	int pl=1;
	initscr();
	//waste time
	
for(int i=0;i<100000;i++)
{
	id+i*i+id;
	
	if(id%1000)
	{  
		/*if we do not lock the stream, we will get scrambled output
		this is the type of situations where we need a controller, 
		a mutex (semaphore)*/
		sprintf(progressStr,"%3.2f%% %s",(float)i/1000,progressBar);
		//progressBar[pl]='#';
		//progressBar[pl+1]='\0';
		//pl++;
		mutex.lock();
		mvprintw(y,x,str.c_str());
		mvprintw(y,x+20,progressStr);
		refresh();
		mutex.unlock();
		//cout<<endl<<id <<" : "<< (float)i/100 <<" Percent completed";
		
		
	}
	
}
endwin();
}
int main(int argc,char * argv[])
{	
	if(!strcmp("par",argv[1]))
	{
	boost::thread workerF1(runnable,1,10,10,string("Thread 1"));
	boost::thread workerF2(runnable,2,10,20,string("Thread 2"));
	boost::thread workerF3(runnable,3,10,30,string("Thread 3"));
	workerF1.join();
	workerF2.join();
	workerF3.join();
	
	workerF1.join();
	
	}
	else
	{
		runnable(1,10,10,string("Thread 1"));
		runnable(2,10,20,string("Thread 2"));
		runnable(3,10,30,string("Thread 3"));
		
	}
	
}	
