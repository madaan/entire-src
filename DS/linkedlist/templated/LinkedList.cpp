//sg
#include<iostream>
#include "LinkedList.h"
using namespace std;
/*
template <class T>
void LinkedList<T>::addHead(T data)
{
Node<T> * newN=new Node<T>();
newN->data=data;
newN->next=head;
head=newN;
}
template <class T>
void LinkedList<T>::reverseList()
{
	Node<T> *prevN,*currN,*nextN,*nexterN;
	currN=head;
	nextN=currN->next;
	prevN=NULL;
	while(currN)
	{
		nextN=currN->next;
		if(!nextN)
		{
			currN->next=prevN;
			head=currN;
			return;
		}
		nexterN=nextN->next;
		nextN->next=currN;
		currN->next=prevN;
		currN=nexterN;
		prevN=nextN;
	}
	head=nextN;
}
template <class T>
void LinkedList<T>::deleteHead()
{
Node<T> temp;
temp=head;
head=head->next;
delete temp;
}

template <class T>
void LinkedList<T>::display()
{
Node<T> * temp=head;
while(temp)
{
cout<<temp->data<<"  " ;
temp=temp->next;
}
cout<<"\n";
}
*/
