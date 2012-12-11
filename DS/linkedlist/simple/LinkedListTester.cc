//sg
#include "LinkedList.h"
#include<iostream>
using namespace std;
int main()
{
int i=1;
LinkedList * myLL=new  LinkedList(i++);//Start with a 0
int done=1,choice;

myLL->addNodeToRear(i++);
myLL->addNodeToRear(i++);
myLL->addNodeToRear(i++);
myLL->addNodeToRear(i++);
myLL->addNodeToRear(i++);


while(done)
{
cout<<"Select the operation that you want to perform: \n";
//the menu
cout<<"\
1.Print List\n\n\
2.Add Node At The Front\n\n\
3.Delete Node From Front\n\n\
4.Add Node at the rear\n\n\
5.Reverse The list Press\n\n\
6.Reverse in blocks of K\n\n\
 Any Other Key To Exit\n\t:";
cin>>choice;

switch(choice)
{
case 1:
myLL->printLinkedList();
break;
case 2:
cout<<"Enter the element to be added";
cin>>choice;
myLL->addNodeToFront(choice);
break;
case 3:
myLL->deleteFromFront();
break;
case 4:
cout<<"Enter the element to be added";
cin>>choice;
myLL->addNodeToRear(choice);
break;
case 5:
myLL->reverseList(myLL->getStart(),NULL,NULL);
cout<<"\nList Reversed!";
myLL->printLinkedList();
break;
case 6:
cout<<"Enter the value of K";
cin>>choice;
myLL->reverseBlocksK(choice);
cout<<"\nList Reversed in blocks of K!";
myLL->printLinkedList();
break;
default:
done=0;
}
}
return 0;
}
