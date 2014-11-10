#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct NODE
{
    int cost;
    char city1[51];
    char city2[51];
    NODE* next;
};

void insertnode(NODE** start)
{
    char ch;
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    scanf("%s", temp->city1);
    scanf("%s", temp->city2);
    temp->cost = 0;
    scanf("%c", &ch);
    temp->next=NULL;

    if(*start==NULL)
        *start=temp;
    else
    {
        temp->next=*start;
        *start=temp;
    }
}

int main()
{
    int t,i,n,j,sum;
    NODE *start=NULL,*start1=NULL,*temp,*temp1,*temp2;

    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        for(j=0; j<n-1; j++)
            insertnode(&start);

        temp=start;

        start1=start;
        start=start->next;
        start1->next=NULL;

        temp=start;
        temp1=start1;
        temp2=start;

        while(temp!=NULL)
        {
            if(strcmp(temp->city1,temp1->city2)==0)
            {
                if(temp==start)
                    start=temp->next;
                else
                    temp2->next=temp->next;
                temp1->next=temp;
                temp->next=NULL;
                temp1=temp;
                temp=start;
                temp2=start;
            }
            else
            {
                temp2=temp;
                temp=temp->next;
            }
        }

        temp=start;
        temp2=start;
        while(temp!=NULL)
        {
            if(strcmp(temp->city2,start1->city1)==0)
            {
                if(temp==start)
                    start=temp->next;
                else
                    temp2->next=temp->next;
                temp->next=start1;
                start1=temp;
                temp=start;
                temp2=start;
            }
            else
            {
                temp2=temp;
                temp=temp->next;
            }
        }

        temp=start1;
        sum=0;
        while(temp!=NULL)
        {   printf("%s ",temp->city1);
            printf("%s ", temp->city2);
            printf("%d$\n", temp->cost);
            sum=sum+temp->cost;
            temp=temp->next;
        }
        printf("%d$\n",sum);
    }
}
