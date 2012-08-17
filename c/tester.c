//sg
#include<stdio.h>
struct test
{
short a,b;
};
int main()
{
/*int x=40,y=35,z=20,w=10;
int a=x*y/z-w;
int b=x*y/(z-w);
printf("%d  %d\n",a,b);
*/
struct test t={1,2};
short c,m=10,a=3;
float p=t.a;
int w=p;
float * pt;
pt=&w;
printf("%f\n",p);
//c=m/a--;
printf("%d\n",a++ + a++ + ++a);
printf("c=%d m=%d a=%d \n",c,m,a);
int x=34.54,y=20,z=-5;
printf("%d",(y>50 && z>10 || x>30));
return 0;
}
