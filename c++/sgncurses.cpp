//sg

#include<ncurses.h>

int main()
{
	initscr();
	printw("Hello world");
	for(int i=0;i<10;i++)
	{
		move(i,10);
		
	printw("Hello world");
}
	//refresh();
	getch();
endwin();
return 0;
}
