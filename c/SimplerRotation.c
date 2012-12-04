//sg
#include<stdio.h>
int main()
{
char seed[100],map[150],input[150],taken[150];

int i=0,mi=0;
for(i=97;i<=122;i++)
taken[i]=0;
printf("\nEnter the seed : ");
scanf("%s",seed);
for(i=0;seed[i];i++)
{
	map[97+i]=seed[i];
	taken[seed[i]]=1;
}
mi=i;
for(i=97;i<=122;i++)
{
	if(!taken[i])
	{
		map[97+mi]=i;
		taken[i]=1;
		mi++;
	}
	
}
/*for(i=97;i<=122;i++)
{
	printf("%c : %c",
}*/
	printf("\nEnter the input : ");
scanf("%s",input);
i=0;
while(input[i])
{
printf("%c",map[input[i++]]);
}
printf("\n");
return 0;
}
