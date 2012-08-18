//sg
#include "polyterm.h"
#include "../templated/LinkedList.h"
#include<iostream>
using namespace std;
class Polynomial
{
 static int MAX;
LinkedList<Term> ll; 
void collect();
public:
Polynomial(int * coeffArr,int * expArr)
{
Term * tmp;
int i=0;
while(coeffArr[i])
{	
tmp=new Term(coeffArr[i],expArr[i]);
ll.addHead(tmp);
i++;	
}
}
friend ostream& operator <<(ostream& o,Polynomial& p);
Polynomial operator +(Polynomial p2)
{
	/*
	 * these are the nodes pointing to the link lists
	 * that represent the 2 polynomials
	 * */
	int coeff[100],exp[100],termCount=0;
	/* node refers to the 
	 * node of the linked list
	 * the data at each node is the pointer to
	 * the linked data
	 */
	  
	Node<Term> * st1=ll.getHead();
	Node<Term> * st2=p2.ll.getHead();
	while(st1&&st2)
	{
		if(st1->data->exp>st2->data->exp)
		{
			coeff[termCount]=st1->data->coeff;
			exp[termCount]=st1->data->exp;
			st1=st1->next; 
			termCount++;
		}
		else if (st1->data->exp==st2->data->exp)
		{
			coeff[termCount]=st1->data->coeff+st2->data->coeff;
			exp[termCount]=st1->data->exp;
			st1=st1->next;st2=st2->next; 
			termCount++;	
		}
		else 
		{
			coeff[termCount]=st2->data->coeff;
			exp[termCount]=st2->data->exp;
			st2=st2->next; 
			termCount++;
		}
	}
	if(st2)
	{
		while(st2)
		{
			coeff[termCount]=st2->data->coeff;
			exp[termCount]=st2->data->exp;
			st2=st2->next; 
			termCount++;
		}
	}
	if(st1)
	{
		while(st1)
		{
			coeff[termCount]=st1->data->coeff;
			exp[termCount]=st1->data->exp;
			st1=st1->next; 
			termCount++;
		}
	}
	coeff[termCount]=0;
	return Polynomial(coeff,exp);
}
Polynomial operator *(Polynomial p2)
{
	Node<Term> * st1=ll.getHead();
	Node<Term> * st2=p2.ll.getHead();
	int coeff[MAX],exp[MAX], termCount=0;
	int currE,currC;// coefficient and exp of st1
	for(;st1;st1=st1->next) //for each st1
	{
		currE=st1->data->exp;
		currC=st1->data->coeff;
		for(Node<Term> * temp=st2;temp;temp=temp->next) 
		//scan through the second list
		{
			coeff[termCount]=temp->data->coeff*currC;
			exp[termCount]=(temp->data->exp+currE);
			termCount++;
		}
	}
	//before we create a polynomial, we must collect all the terms
	
	coeff[termCount]=0;
	
	Polynomial p= Polynomial(coeff,exp);
	p.collect();
	return p;
} 
};
void Polynomial::collect()
{
	int coeff,exp;
	//here we never delete head
	Node<Term> * head=ll.getHead();
	Node<Term> * temp=NULL,*prev=NULL;
	while(head)
	{
		prev=head;
		temp=head->next;
		coeff=head->data->coeff;
		exp=head->data->exp;
		while(temp)
		{
			if(temp->data->exp==exp)
			{
				coeff+=temp->data->coeff;
				ll.deleteNode(prev);
				temp=temp->next;
			}
			/*prev should not be updated in case a node is deleted.
			*because then it would be pointing to a deleted node*/
			else
			{
			prev=temp;
			temp=temp->next;
			}
		}
		head->data->coeff=coeff;
		head=head->next;
	}
	
}
ostream& operator <<(ostream& o,Polynomial& p)
{
	Node<Term> * st=p.ll.getHead();
	if(!st)
	{	cout<<"Polynomial=0\n";
		return o;
	}
	for(;st->next;st=st->next)
	{
		cout<<(*(st->data))<<" + ";
	}
	cout<<(*(st->data))<<"\n";
	return o;
}
int Polynomial::MAX=100;
int main()
{
	cout<<"Testing poly\n";
	int c[10];
	int e[10];
	int c1[10];
	int e1[10];
	for(int i=1;i<9;i++)
	{
		c[i-1]=i;
		e[i-1]=i;
		c1[i-1]=2*i;
		e1[i-1]=2*i;
	}
	c1[8]=c[8]=0;
		Polynomial p1(c,e),p2(c1,e1);
	Polynomial p3=p1+p2;
	cout<<p1<<p2;
	//cout<<p3;
	p3=p1*p2;
	cout<<p3;
	
	return 0;
}
