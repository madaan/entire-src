//sg
#include<iostream>
using namespace std;
template <class T>
struct Node
{
T * data;
Node * next;
};
template <class T>
class LinkedList
{
Node<T> * head;

public : 
LinkedList()
{
head=NULL;
}
Node<T>* getHead();
void addHead(T * data);
void deleteHead();
void deleteNode(Node<T> * prevPtr);
void display();
void reverseList();
void intersect(LinkedList<T> ll2);
bool searchNode(T * data);
void unionList(LinkedList<T> ll2);
bool isCycle();
};
template <class T>
void LinkedList<T>::deleteNode(Node<T> * prevPtr)
{
	Node<T> * tmp=prevPtr->next;
	
	prevPtr->next=prevPtr->next->next;
	delete tmp;
}

template <class T>
bool LinkedList<T>::isCycle()
{
	Node<T> * p1=head;
	Node<T> * p2=head;
		p2=p2->next->next;
		p1=p1->next;
	while((p1!=p2)&&p2&&p2->next)
	{
		if(p1==p2)
		return true;
		p2=p2->next->next;
		p1=p1->next;
	}
	if(!p2)
	return false;
}

template <class T>
void LinkedList<T>::unionList(LinkedList<T> ll2)
{
	
	Node<T> * temp=head;
	Node<T> * t2=ll2.getHead();
	
	while(temp)
	{
		cout<<(*(temp->data))<<" ";
		temp=temp->next;
	}
	
	while(t2)
	{
		if(!searchNode(t2->data))
		{
			cout<<(*(t2->data))<<" ";
		}
		t2=t2->next;
	}
}
template <class T>
void LinkedList<T>::intersect(LinkedList<T> ll2)
{
	
	Node<T> * t1=head;
	Node<T> * t2=ll2.getHead();
	while(t2&&t1)
	{
		if(searchNode(t2->data))
		{
			cout<<(*(t2->data))<<" ";
		}
		t2=t2->next;
		t1=t1->next;
	}
}
template <class T>
bool LinkedList<T>::searchNode(T * data)
{
Node<T> * temp=head;
if(!temp)
return false;

while(temp)
{
	if(*(temp->data)==*data)
	return true;		
	temp=temp->next;
}
return false;
}
template <class T>
Node<T>* LinkedList<T>::getHead()
{
	return head;
}

template <class T>
void LinkedList<T>::addHead(T * data)
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
cout<<*(temp->data)<<"  " ;
temp=temp->next;
}
cout<<"\n";
}
