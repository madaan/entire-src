//sg
#include<iostream>
#include "tree.h"
#include "Char.cpp"
using namespace std;
int main()
{
	Char rootVal('a');
	cout<<"Enter root node value " ;
	cin>>rootVal;
	Tree<Char> * t=new  Tree<Char>(rootVal);
	cin>>(*t);
	t->prettyPrint(t->getHead());
	t->prettyPrint(t->getMirror(t->getHead()));
	t->treeStatPrinter();
	
	//a tree of integers
	int treeR;
	cout<<"\n\n\nEnter root node value " ;
	cin>>treeR;
	Tree<int> * t2=new  Tree<int>(treeR);
	cin>>(*t2);
	t2->prettyPrint(t2->getHead());
	
	return 0;
}
