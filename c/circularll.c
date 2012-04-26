//sg
#include<stdio.h>
typedef struct CLL
{
int data;
struct CLL * next;
}cll;
void insert(cll ** start,int data)
{
if((*start)==NULL) //first entry?
{
*start=(cll *)malloc(sizeof(cll));
(*start)->data=data;
(*start)->next=(*start);
}
else
{
cll * newn=(cll *)malloc(sizeof(cll));
newn->data=data;
cll * temp=(*start)->next;
//get the tail
while((temp->next)!=*start)
{
temp=temp->next;
}
#ifdef DEBUG
printf("found the last node : %d",temp->data);
#endif
//temp now has the last node
newn->next=(*start);
temp->next=newn;
(*start)=newn;
}
}
void print(cll * start)
{
if(start==NULL)
{
printf("LIST IS EMPTY");
return;
}
printf("\nOk,Will Print Now\n");
cll * temp=start->next;
printf("First Node : %d ",start->data);

while(temp!=start)
{
printf("%d ",temp->data);
temp=temp->next;

}
printf("\n");
}
main()
{
cll * begin=NULL;
int ch,entry;
while(1)
{
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("ENTER THE ELEMENT TO INSERT : ");
scanf("%d",&entry);
printf("\n");
insert(&begin,entry);
print(begin);
break;
case 2:
print(begin);
break;
default:
exit(0);
}
}
}
