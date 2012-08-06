//sg
#include<iostream>
#include<stdlib.h>
using namespace std;
const int CAPACITY=100;
template <class T>
class Stack
{
	
	T stackEle[CAPACITY];
	int top;
	public:
	Stack()
	{
		top=-1;
	}
	void push(T data);
	T pop();
	void printStack();
	void reverseStack();
	
};
template <class T>
void Stack<T>::reverseStack()
{
	if(top==-1)
	return;
	T temp=pop();
	reverseStack();
	push(temp);
	
}
template <class T>
void Stack<T>::push(T data)
{
	if(top==99)
	{
		cout<<"Stack Overflow!\n";
		return;
	}
	stackEle[++top]=data;
}
template <class T>
T Stack<T>::pop()
{
	
	if(top==-1)
	{
		cout<<"Stack Empty!\n";
		exit(-1);
	}
	return stackEle[top--];
}
template <class T>
void Stack<T>::printStack()
{
	
	if(top==-1)
	{
		cout<<"Stack Empty!\n";
		exit(-1);
	}
	cout<<"->";
	cout<<stackEle[top]<<"\n";
	for(int i=top-1;i>=0;i--)
	cout<<"  "<<stackEle[i]<<"\n";
}
struct emp
{
	string name;
	int id;
	public:
	emp():id(0),name("")
	{
		
	}
	emp(string name,int id)
	{
		this->id=id;
		this->name=name;
	}
	friend ostream& operator <<(ostream& o,emp e);
};
ostream& operator <<(ostream& o,emp e)
{
	o<<"\n_______________________________\n";
	o<<"Name : "<<e.name<<"\nID: "<<e.id;
	o<<"\n_______________________________\n";
	return o;
}


int main()
{
	Stack<emp> st;
	st.push(emp("sg",1));
	st.push(emp("this is sony vaio",2));
	st.push(emp("this is apple ipad",3));
	st.printStack();
	st.pop();
	st.pop();
	st.printStack();
	st.pop();
	st.printStack();
	return 0;
}
	
