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
	bool res1=t->isMirror(t->getHead(),t->getMirror(t->getHead()));
	if(res1)
	cout<<"Mirrors!";
	bool res2=t->isMirror(t->getHead(),t->getHead());
	if(res2)
	cout<<"Mirrors!";
	else
	cout<<"Not Mirrors";
	
	//a tree of integers
	int treeR;
	cout<<"\n\n\nEnter root node value " ;
	cin>>treeR;
	Tree<int> * t2=new  Tree<int>(treeR);
	Tree<float> * t3=new Tree<float>(treeR);
	cin>>(*t3);
	t3->prettyPrint(t3->getHead());
	
	return 0;
}
