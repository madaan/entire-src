//sg
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
long square(long s){
return s*s;
}
 long bigmod(long b, long p, long m){
if (p == 0)
return 1;
else if (p%2 == 0)
return square( bigmod (b,p/2,m)) % m; // square(x) = x * x
else
return ((b % m) * bigmod( b,p-1,m)) % m;
}

char ip[100000];
int main()
{
 int numberStringLength=0;
int prevGroup=0,curGroup;
int l;
char ch;
 long answer[10];
int cases,temp,i;
//freopen("ip","r",stdin);
//freopen("op","w",stdout);
scanf("%d",&cases);
for(int C=0;C<cases;C++)
{
  i=0;
if(C==0)
{
cin.ignore(1,'\n');
}
cin.getline(ip,100000,'\n');
//cout<<ip<<endl;
if(strlen(ip)==0)
{
  answer[C]=0L;
  continue;
}
while((ch=ip[i++])!='\0')
{
  //____________________GET LENGTH_____________________
switch(ch)
{
case 'a':
case 'd':
case 'g':
case 'j':
case 'm':
case 'p':
case 't':
case 'w':
temp= 1;
break;
case 'b':
case 'e':
case 'h':
case 'k':
case 'n':
case 'q':
case 'u':
case 'x':
temp= 2;
break;
case 'c':
case 'f':
case 'i':
case 'l':
case 'o':
case 'r':
case 'v':
case 'y':
temp= 3;
break;
case 's':
case 'z':
temp= 4;
break;
}
numberStringLength+=(temp-1);
//______________________GET GROUP___________________
switch(ch)
{
case 'a':
case 'b':
case 'c':
curGroup= 2;
break;
case 'f':
case 'd':
case 'e':
curGroup= 3;
break;
case 'g':
case 'h':
case 'i':
curGroup= 4;
break;
case 'j':
case 'k':
case 'l':
curGroup= 5;
break;
case 'm':
case 'n':
case 'o':
curGroup= 6;
break;
case 'p':
case 'q':
case 'r':
case 's':
curGroup= 7;
break;
case 't':
case 'u':
case 'v':
curGroup= 8;
break;
case 'w':
case 'x':	
case 'y':
case 'z':
curGroup= 9;
break;
}
//___________________________________________________
if(curGroup==prevGroup)
{
numberStringLength++;
}
prevGroup=curGroup;
}//end while
answer[C]=bigmod(2,numberStringLength,100000007);
numberStringLength=0;
prevGroup=0;
}  //for all cases	
for(int j=0;j<cases;j++)
{
 printf("%ld\n",answer[j]);
}
return 0;
}