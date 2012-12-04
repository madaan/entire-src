//sg
#include<stdio.h>
#define TRUE 1
#define FALSE 0
/* The next 2 functions completely specifies 
 * the NFA. These functions can be modified 
 * to accomodate as complex an NFA as required*/
char * getNextState(char state,char input)
{
	if(state=='a')
	{
		if(input=='1')
		return "a";
		else
		return "ab";
		
	}
	else //state b
	{
		if(input=='1')
		return NULL;
		else
		return NULL;
	}
}
int isFinal(char state)
{
	return (state=='b')?TRUE:FALSE;
}
int nfa(char state,char * ip)
{
	char * nextState;
	if(*ip=='$')//end of input
	{ //check if we have reached final state or not
	if(isFinal(state))
	{
		return TRUE;
	}
	//no, must return false
	return FALSE;
	}
	if((nextState=getNextState(state,*ip)))
	{
		do
		{
			//one by one, go to each state and see if we have a success
			if(nfa(*nextState++,ip+1))
			return TRUE;
			
			
		}while(*nextState);
	}
	//no next state left, should return FALSE now
	return FALSE;
}
int main()
{
	if(nfa('a',"000101010101010100000101010101010100000$"))
	{
		printf("Success!");
	}
	else
	{
		printf("Failure!");
	}
	return 0;
}
