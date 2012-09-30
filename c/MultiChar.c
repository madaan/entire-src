//sg
#include<stdio.h>
int main()
{
	char testChar='abcde';
	printf("%c",testChar);
	char * testPtr=&testChar;
	printf("%c,%c,%c,%c",*(testPtr+0),*(testPtr-1),*(testPtr-2),*(testPtr-3));
	 char test = 'a';
        char test2 = 'b';
        char test3 = 'cde';
        cout<<&test<<endl<<&test2<<endl<<&test3;
        return 0;
}
