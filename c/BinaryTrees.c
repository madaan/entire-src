//sg
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
int level;
struct node * l,*r;
};
typedef struct node node;
node * queue[100];//for reading and for traversing 
void readTree(node * root)
{
node * temp;
int lcd,rcd,front=0,rear=0;
queue[rear++]=root;//fill with root
while(front<rear)//while queue has elements
{
printf("Enter the left child of %d (0 to terminate link)" ,queue[front]->data);
scanf("%d",&lcd);
printf("Enter the right child of %d (0 to terminate link)",queue[front]->data);
scanf("%d",&rcd);
if(lcd)
{
temp=(node *)malloc(sizeof(node));
temp->data=lcd;
temp->l=temp->r=NULL;
queue[front]->l=temp;
queue[rear++]=temp;
}
if(rcd)
{
temp=(node *)malloc(sizeof(node));
temp->data=rcd;
temp->l=temp->r=NULL;
queue[front]->r=temp;
queue[rear++]=temp;
}
front++;
}
}
void inorder(node * head)
{
if(head)
{
inorder(head->l);
printf("%d  ",head->data);
inorder(head->r);
}
}
void printOnSameLevel(node * root)
{
int front,rear;
front=rear=0;
//assuming maximum of 7 levels
node * rec[7][100];
queue[rear++]=root; //init queue
int level=0;
while(front<rear) //BFS
{
if(queue[front]->l)
{
queue[rear]=queue[front]->l;
queue[rear]->level=queue[front]->level+1;
rear++;
}

if(queue[front]->r)
{
queue[rear]=queue[front]->r;
queue[rear]->level=queue[front]->level+1;
rear++;
}
front++;
}
int i=0;
level=queue[i]->level;
printf("\nLevel %d \n",level);
while(i<rear)
{
printf("%d ",queue[i]->data);
i++;
if(queue[i]&&queue[i]->level>level)
{
level=queue[i]->level;
printf("\nLevel %d \n",level);
}
}
}
void findAncestor(node * root,int child1,int child2)
{
node * hops[20];//array to store intermediate hops that were needed to reach element
int count=0;
track(root,child1,hops,&count);
int i=0;
while(i<count)
{
if(DFS(hops[i],child2))
{
printf("\nCommon Ancestor : %d",hops[i]->data);
break;
}
i++;
}
}
int track(node * root,int target,node * hops[],int * curr)
{
if(root==NULL)
{
return 0;
}
if(  (  (root->l)  && ((root->l)->data==target) )  ||((root->r)&&((root->r)->data==target)  )) //found 
{
//first node to reach the target
hops[*curr]=root;
(*curr)++;
return 1;
}
//no luck, try finding the target in children
//may be the root or any child
if(track(root->l,target,hops,curr)||track(root->r,target,hops,curr))
{
hops[*curr]=root;
(*curr)++;
return 1;
}
//not found anywhere
return 0;
}
int DFS(node * origin, int target)
{

node * stack[100],*temp;
int top=-1;
stack[++top]=origin;
while(top>=0)
{
temp=stack[top];
if(temp->data==target)
return 1;
else //continue DFS
--top;
if(temp->l)
stack[++top]=temp->l;
if(temp->r)
stack[++top]=temp->r;
}
return 0;
}
int main()
{
int c1=1,c2=1;
node * root=(node *)malloc(sizeof(node));
printf("Enter the contents of the root : ");
scanf("%d",&root->data);
root->l=root->r=NULL;
root->level=0;
readTree(root);
printOnSameLevel(root);
while(c1&&c2)
{
printf("\nFind out the nodes whose ancestor is to be found : ");
scanf("%d%d",&c1,&c2);
findAncestor(root,c1,c2);
}
return 0;
}






