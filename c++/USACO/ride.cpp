/*
 * ID: madaan.1 
 * LANG: C++
 * TASK: ride
 * */
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
char comet[7],group[7];
int cometNum=1,groupNum=1,c,g;
ofstream of("ride.out");
ifstream fi("ride.in");
fi>>comet;
fi>>group;
for(int i=0;i<strlen(comet);i++)
{
c=comet[i];
c-=64;
cometNum*=c;
}

for(int i=0;i<strlen(group);i++)
{
g=group[i];
g-=64;
groupNum*=g;
}
if(cometNum%47==groupNum%47)
of<<"GO";
else
of<<"STAY";
return 0;
}

