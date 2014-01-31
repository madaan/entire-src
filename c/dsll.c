//sg
#include<stdio.h>
#include<stdlib.h>
typedef struct linkedList
{
  int info;
  struct linkedList * next;
  
}ll;
//hash table for 100 elements max
ll * hash[100];
int count;

main()
{
  ll * start=NULL;
  int ch;
  while(1)
  {
    printf("\n1. Add an element \n2. Get an element \n3.Exit");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
	printf("\nEnter the element to be inserted : ");
	scanf("%d",&ch);
	addElementToList(&start,ch);
	printf("Element Added");
	break;
      case 2:
	printf("\nEnter the index");
	scanf("%d",&ch);
	getElement(ch);
	break;
      default:
	exit(0);
    }
    
  }
  
}

//add an element to the list
void addElementToList(ll ** start,int info)
{
 ll *  temp=(ll *)malloc(sizeof(ll));
  
    temp->info=info;
    temp->next=NULL;
  if((*start)==NULL)
  {
    *start=temp;
  }
  else
  {
    (*start)->next=temp;
  }
  hash[count++]=temp;
  
}
//get an element to the list
void getElement(int index)
{
  printf("\nValue : %d ",(hash[index]->info));
}

  