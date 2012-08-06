//sg
#include<stdio.h>
typedef struct node
{
int data;
struct node * next;
struct node * prev;
}node;
void add(node ** start,node ** rear,int data)
{
node * temp=*start,*new;
new=(node *)malloc(sizeof(node));
new->data=data;
if(temp==NULL)
{
new->next=NULL;
new->prev=NULL;
*start=new;
*rear=new;
return;
}
new->next=NULL;
new->prev=temp;
temp->next=new;
*rear=new;
}
void print(node * start)
{
while(start!=NULL)
{
printf("%d-",start->data);
start=start->prev;
}
printf("\n");
}
main()
{
node * start=NULL,*rear;
add(&start,&rear,4);
add(&start,&rear,5);
print(rear);
}
