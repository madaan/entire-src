#include<stdio.h>
main()
{
int i=0;
scanf("%d",&i);
while(malloc(10000))
{

printf("\nAllocating Block Number %d (10 Kb)",i++);
}

}
