//sg
#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"
/*Operations that can be performed on an object of linked list
 *
insertion at the front
deletion from the front
Addition at the last
*/

/* FUNCTION
 * Add node to the front :
 * takes an  integer,internally creates a new node and sets it to start*/
void LinkedList::addNodeToFront(int n)
{
//create the value
Node * newNode=new Node(n);
if(!newNode)
{
puts("Failed to allocate memory,Program must now exit");
exit(1);
}
//save the value of save
Node * temp=start;
//now update start
start=newNode;
//set next to right value
newNode->next=temp;
puts("Added a node to the front");
}

/*FUNCTION 
 * Print Linked List*/
void LinkedList::printLinkedList()
{
Node * temp=start;
//first print a patteren
int  rows=2;
while(rows--)
{
puts("--------");
}
while(temp)
{
printf("%d->",temp->data);
temp=temp->next;
}
puts("NULL");
rows=2;
while(rows--)
{
puts("--------");
}
}
/*FUNCTION
 *Deleting a node from the front
 */
void LinkedList::deleteFromFront()
{
start=start->next;
puts("Deleted a node from the front");
}


/* Function
 * Takes the integer to be inserted in the linked list
 * Adds it to the last of the queue.
 */
void LinkedList::addNodeToRear(int n)
{
Node * newNode=new Node(n);
Node * temp;
for(temp=start;temp->next;temp=temp->next)
{
}
//at this point ,temp is pointing to the last element.
//Now add it here
temp->next=newNode;
//done
}
