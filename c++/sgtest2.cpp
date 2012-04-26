//sg
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
using namespace std;
main()
{
ofstream of("TEST");
of<<"1\n";
of<<"100 1000\n";
//for each chef,assign a speciality
for(int i=0;i<400;i++)
{
for(int j=1;j<10;j+=2)
{
of<<j<<" ";
}
}
of<<"\n";
for(int i=0;i<400;i++)
{
for(int j=2;j<11;j+=2)
{
of<<j<<" ";
}
}
}
