//sg
/* A simple program to demonstrate the use of function pointers.
 * Here a function , divisor, takes as an argument the dividend, divisor
 * as well as the function that will be called in case of an error.
 * This is like telling one function what code to run in case of an
 * error.
 */
#include<iostream>
using namespace std;
const float INF=100000.0f;
float errorhandler1()
{
    cout<<"\nError : Handler 1 returning 0\n";
    return 0.0;
}
float errorhandler2()
{
    cout<<"\nError : Handler 2 returning INF\n";
    return INF;
}
float divisor(int x,int y,float (*errorH)())
{
    if(y==0)
    {
        return (*errorH)();
    }
    else
        return (x/y);
}
int main()
{
    cout<<divisor(2,3,errorhandler1)<<"\n";
    cout<<divisor(2,0,errorhandler1)<<"\n";
    cout<<divisor(2,0,errorhandler2)<<"\n";
    return 0;
}

