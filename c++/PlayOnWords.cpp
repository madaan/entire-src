//sg
#include<stdio.h>
#include<string.h>
#include<iostream>
#define undebug
using namespace std;
int main()
{
	int N,i,start[26]={0},end[26]={0};
	int sChar,eChar,l,diff,cases,inBetween;
	char buff[1001];
	bool foundStart=false,foundEnd=false,isOrderable=true;
	scanf("%d",&cases);
	while(cases--)
	{
		//refresh
		foundStart=false,foundEnd=false,isOrderable=true;
		inBetween=0;
		for(int t=0;t<26;t++)
		{
			start[t]=end[t]=0;
		}
	scanf("%d",&N);
	i=N;
	if(N==2)
	{
	int sChar2,eChar2;
	//read first 
	scanf("%s",buff);
	
	sChar=static_cast<int>(buff[0])-97;
	eChar=static_cast<int>(buff[1])-97;
	//read next
	scanf("%s",buff);
	sChar2=static_cast<int>(buff[0])-97;
	eChar2=static_cast<int>(buff[1])-97;
	if((eChar==sChar2)||(eChar2==sChar))
	{
		isOrderable=true;
	}
	else
	{
		isOrderable=false;
	}
	}
	else  //more than 2
	{
	while(i--)
	{
	scanf("%s",buff);
	l=strlen(buff);
	sChar=static_cast<int>(buff[0])-97;
	eChar=static_cast<int>(buff[l-1])-97;
	start[sChar]++;
	end[eChar]++;
	}
	#ifdef debug
	for(int j=0;j<26;j++)
	{
		cout<<static_cast<char>(j+97)<<"  "<<start[j]<<"  "<<end[j]<<endl;
	}
	#endif
	for(int j=0;j<26;j++)
	{
		diff=end[j]-start[j];
		
		if((diff>1)||(diff< -1))
		{
			isOrderable=false;
			
			break;
		}
		else if(diff==1)
		{
			#ifdef debug
			cout<<"found end as "<<static_cast<char>(j+97)<<endl;
			#endif
			if(foundEnd==true) //already got one?
			{
				isOrderable=false;
				break;
			}
			//found end, sa ab ba
			foundEnd=true;
		}
		else if(diff==-1)
		{
			#ifdef debug
			cout<<"found start as "<<static_cast<char>(j+97)<<endl;
			#endif
			if(foundStart==true) //already got one?
			{
				isOrderable=false;
				break;
			}
			//found start, sa ab ba
			foundStart=true;
		}
		else
		{
			inBetween++;
		}
	
	}
	if(!foundStart||!foundEnd) //eq to inBetween!=N-2
	{
		isOrderable=false;
	}
	
	} //end case for N!=2
	if(isOrderable)
	{
		printf("Ordering is possible.\n");
	}
	else
	{
	printf("The door cannot be opened.\n");
	}
	#ifdef debug
	cout<<"\n"<<isOrderable<<"\n"<<foundStart<<"\n"<<foundEnd<<"\n";
	#endif
}
return 0;
}
	
