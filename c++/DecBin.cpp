//sg
#include<stdio.h>
#include<iostream>
using namespace std;
char * decimalToBin(unsigned long long decimal,int bit)
{
    char *res=new char[sizeof(char)*(bit+1)];

    int i=0;
    unsigned long long mask=1<<(bit-1);
    while(i<bit)
    {
        if(decimal&mask)
        {
            res[i]='1';
        }
        else
        {
            res[i]='0';
        }
        i++;
        mask=mask>>1;
    }
    res[i]='\0';
    return res;
}
long long binToDec(char * bin,int bit)
{
    long long power=1<<(bit-1);
    long long res=0;
    int i=0;
    while(i<bit)
    {
        if(bin[i]=='1')
        {
            res+=power;
        }
        power=power>>1;
        i++;
    }
    return res;
}
int main()
{
    short a=23,b=43;
    unsigned long long x=83343;

    printf("\n%s",decimalToBin(a,8));
    printf("\n%s",decimalToBin(b,16));
    printf("\n%lld",binToDec(decimalToBin(x,31),31));


    return 0;
}
