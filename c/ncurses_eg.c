//sg
#include<ncurses.h>
#include<stdlib.h>
int xyz();

int main()
{

    initscr();
    start_color();                  /* Start color                  */
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    xyz();
    char str[]="banner  \"There You Go\"";
    system(str);
    refresh();
    getch();
    endwin();
}
int xyz()
{
    char * msg="Hello World";
    int ch;
    initscr();                      /* Start curses mode            */
    raw();                          /* Line buffering disabled      */
    keypad(stdscr, TRUE);           /* We get F1, F2 etc..          */
    noecho();                       /* Don't echo() while we do getch */
    printw("Type any character to see it in bold\n");
    ch = getch();                   /* If raw() hadn't been called
                                         * we have to press enter before it
                                         * gets to the program          */
    if(ch == KEY_F(1))              /* Without keypad enabled this will */
        printw("F1 Key pressed");/*  not get to us either       */
    /* Without noecho() some ugly escape
     * charachters might have been printed
     * on screen                    */
    else

    {
        start_color();                  /* Start color                  */
        init_pair(1, COLOR_RED, COLOR_BLACK);
        printw("The pressed key is ");
        attron(COLOR_PAIR(1));
        printw("%c", ch);
        attroff(A_BOLD);
    }
    int row,col;

    refresh();
    getch();
    endwin();                       /* End curses mode                */

    return 0;
}
