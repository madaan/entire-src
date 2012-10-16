//sg
#include<stdio.h>
#include<string.h>
int checkChar(char c)
{
	if((c>=97)||(c<=122))
	{
		if((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'))
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	return 3;
}
char * replacer(char * str,int l)
{
char * temp=(char * )malloc(l*3*sizeof(char)+1);
int ni=0,i;
for( i=0;i<l;i++)
{
	switch(checkChar(str[i]))
	{
		case 1:
		temp[ni]=temp[ni+1]=temp[ni+2]=str[i];
		ni++;
		ni++;
		ni++;
		break;
		case 2:
		temp[ni]=temp[ni+1]=temp[ni+2]=str[i];
		ni++;
		ni++;
		break;
		case 3:
		temp[ni]=str[i];
		ni++;
		break;
	}
}
temp[ni]='\0';
return temp;
}
char * revolver(char * str,int l)
{
	char * temp=(char *)malloc((l+4)*sizeof(char));

	char * stack[10];
	int top=0;
	char buff[32];
	int i=0,bptr=0;
	for(i=0;i<10;i++)
	{
		stack[i]=(char *)malloc(30*sizeof(char));
	}
	i=0;
	while(str[i])
	{
		if(str[i]!=' ')
		{
		//	printf("Copying %c %d \n",str[i],str[i]);
			buff[bptr++]=str[i];
		}
		else
		{
			buff[bptr]='\0';
			strcpy(stack[top],buff);
			top++;
			bptr=0;
		}
		i++;
	}
	//the last word is still in the buffer
	buff[bptr]='\0';
	strcpy(stack[top],buff);
	top++;
	//popping
	int mI=0,j;
	
	for(i=top-1;i>=0;i--)
	{
		//printf("%s\n",stack[i]);
		j=0;
		while(stack[i][j]&&stack[i][j]!='\n')
		{
		temp[mI++]=stack[i][j++];
		}
		temp[mI++]=' ';
	}
	temp[mI]='\0';
	return temp;
}
	

char * sirify(char * str)
{
char * trans;
int l=strlen(str);

trans=replacer(str,l);

trans=revolver(trans,l);
return trans;
}
int main()
{
	int N,dummy;
	char str[100];
	scanf("%d",&N);
	//scanf("\n%d",&dummy);
	//N++;
	while(N--)
	{
	scanf("\n%d",&dummy);
	fgets(str,100,stdin);
	printf("\n%s",sirify(str));
	}
	return 0;
}
