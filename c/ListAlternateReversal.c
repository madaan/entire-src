//sg
#include<stdio.h>
 struct node
{
int data;
struct node * next;
};
typedef struct node node;
void reverseList(node ** head)
{
//base cases
if(*head==NULL)
return;
if((*head)->next==NULL)
return;

//there are atleast 2 nodes
node * p1,*p2,*p3;
p1=*head;
p2=p1->next;
p3=p2->next;
//first exchange
*head=p2;
p2->next=p1;
p1->next=p3;
while((p1)&&(p2=p1->next)&&(p3=p2->next))
{
p2->next=p3->next;
p3->next=p2;
p1->next=p3;
p1=p2;
}
}
void append(node * head,int data)
{
node * new=(node *)malloc(sizeof(node));
new->data=data;
while((head->next)&&(head=head->next));
head->next=new;
}
//assume non null head always
void print(node * head)
{
while(head)
{
printf("%d ",head->data);
head=head->next;
}
printf("\n");
}
int main()
{
node * head=(node *)malloc(sizeof(node));
head->data=0;
int i=0;

for(i=1;i<100000;i++)
{
append(head,i);
}
print(head);
reverseList(&head);
print(head);
return 0;
}
