//sg
#include<stdio.h>
#include "../NodeDef/Node.h"
//Singly linked list
//
//forward declaration

class LinkedList
{
Node * start;
public :
LinkedList(int n)
{
start=new Node(n);
}
void addNodeToFront(int n);
void printLinkedList();
void deleteFromFront();
void addNodeToRear(int n);
};
