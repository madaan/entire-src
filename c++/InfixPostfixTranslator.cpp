//sg
#include<iostream>
#include<ctype.h>
using namespace std;
class Parser
{
	char input[100];
	int lookahead;
		public:
	bool term()
	{
		if(isdigit(input[lookahead]))
		{
			cout<<input[lookahead];
			lookahead++;
			return true;
		}
		return false;
	}
	bool match(char c)
	{
		if(input[lookahead]==c)
		{
			lookahead++;
			return true;
		}
		return false;
	}
	void expr()
	{
		term();
		rest();
	}
	bool rest()
	{
		int lookaheadbu=lookahead;
	   return (match('+')&&term()&&(cout<<"+")&&rest())||(lookahead=lookaheadbu,match('-')&&term()&&(cout<<"-")&&rest());
	}

	Parser()
	{
		lookahead=0;
		cin>>input;
	}	
};
int main()
{
	
	Parser p;
	p.expr();
}
