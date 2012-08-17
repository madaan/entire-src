//sg
/*
 * Class to represent a term of the form coeff.x^exp (3x^5)
*/
#include<iostream>
using namespace std;
class Term
{
public:
int exp,coeff;
Term(int coeff,int exp)
{
	this->coeff=coeff;
	this->exp=exp;
}
Term()
{
	exp=coeff=0;
	
}
friend ostream& operator <<(ostream& o,Term& t);
};
ostream& operator <<(ostream& o,Term& t)
{
	cout<<t.coeff<<"x^"<<t.exp;
	return o;
}
