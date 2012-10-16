//sg
#include<stdio.h>
#include<unistd.h>
int main()

{
	int a=0;
	pid_t cp;
	
	char * a1[][2]={{"a","1"},{"b","2"}};
	printf("%s",a1[1][0]);
if((cp=fork())==0)//child
{
	a=a+5;
	
	printf("\n%d %p\n",a,&a);
	
}
else
{
	a=a-5;
	printf("\n%d %p\n",a,&a);
//	waitpid(cp);
}

return 0;
}
