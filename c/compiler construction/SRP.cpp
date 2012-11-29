//sg
/* Shift reduce parsing : Form of bottom up parsing where the stack holds 
grammar symbols and an input buffer holds rest of the string. 

The tricky part is to decide when to shift and when to reduce, this 
program illustrates the shift reduced parsing by taking the following 
sample grammar : 
	E->E+T|T
	T->T*F|F
	F->(E)|id
	E : Expression T: Terminal
	F: Factor 
Simplistic assumptions have been made.
To create an actual Shift reduced parser, you would go for something like
an LR parser. Usually, bottom up parsers are created using tools.
*/
#include<iostream>
#include<string.h>
using namespace std;
class SRP
{
	char stack[200]; //to hold symbols
	char input[200]; //input : tokens
	int top; //stack top
	int iptr; //input pointer
	const int NUM_PRODUCTIONS;
	static char * grammar[7][2];
	char START;
	
	
/*reduces the stack starting from i to the end by using production number
 * proIndex*/
void reduce(int i,int proIndex)
{
	cout<<"\nReducing using "<<grammar[proIndex][0]<<" -> "<<grammar[proIndex][1]<<endl;
	int l=strlen(grammar[proIndex][0]);
	
	strcpy(stack+i,grammar[proIndex][0]);
	
	//update stack top
	top=i+l;
}
//returns the row index of the production if it is a reduce,-1 otherwise 
int isHandle(char * str)
{
	for(int i=0;i<NUM_PRODUCTIONS;i++)
	{
		if(!strcmp(grammar[i][1],str))
		{
			return i;
		}
	}
	return -1;
}
void parse()
{
	char temp[200];

	int x;
	bool shift=true,error=false,accepted=false;
	do
	{
	//shift or reduce ? 
	//match longest stack top
	//as i increases, the chunk to be copied on stack top would be 
	//smaller
	for(int i=0;i<top;i++)
	{
		//assert no match will be there
		shift=true;
		
		strcpy(temp,stack+i);
		//cout<<"Matching : "<<temp<<"\n";
		x=isHandle(temp);
		//cout<<"Is handle returned "<<x<<endl;
			
		
		if(x!=-1) //its a reduce
		{
			reduce(i,x);
			shift=false;
			break;
		}
		
	}
	if(shift)
	{
		cout<<"Shifting "<<input[iptr]<<"\n";
		if((input[iptr]=='\0')&&(top!=1))
		{
			error=true;
			break;
		}
		else if(input[iptr])
		{
		//shift
		stack[top++]=input[iptr++];
		stack[top]='\0';
		
		}
	}
	//check if accepted
	if((top==1)&&stack[top-1]==START&&(!input[iptr]))
	{
				accepted=true;
				error=false;
				break;
	}
	//cout<<"Error = "<<error<<endl;
	//cout<<"Top = "<<top<<endl;
	cout<<"\n###############";
	cout<<"\nStack : "<<stack<<"   Input : "<<(input+iptr)<<endl;
	}while((!error)&&(!accepted));
cout<<"\n###############";
	cout<<"\nStack : "<<stack<<"   Input : "<<(input+iptr)<<endl;
	
	if(error==true)
	{
		
		cout<<"Syntax error detected! \n ";
	}
	if(accepted)
	{
		cout<<"String accepted!\n";
	}
	
}

	public:
	SRP():NUM_PRODUCTIONS(7)
	{
		START='E';
		cout<<"Enter the token string : ";
		cin>>input;
		iptr=0;
		top=0;
		stack[top]='\0';
		parse();
	}

};

 char * SRP::grammar[][2]=
	{
		{"E","E+T"},
		{"E","T"},
		{"T","T*F"},
		{"T","F"},	
		{"F","(E)"},
		{"F","I"},
		{"E","E*E"}
	};
	int main()
	{
		SRP s;
	
		return 0;
	}
