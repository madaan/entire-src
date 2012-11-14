//sg
#include "LinkedList.h"
#include<iostream>
using namespace std;
int main()
{
LinkedList * myLL=new  LinkedList(0);//Start with a 0
int done=1,choice;
while(done)
{
cout<<"Select the operation that you want to perform: \n";
cout<<"1.Print List\n2.Add Node At The Front\n3.Delete Node From Front\n4.Add Node at the rear\n5.Reverse The list Press Any Other Key To Exit\n\t:";
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
myLL->reverseList(myLL->getStart(),NULL);
cout<<"\nList Reversed!";
myLL->printLinkedList();

break;
default:
done=0;
}
}
return 0;
}
