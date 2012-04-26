//sg
#include<stdarg.h>
#include<stdio.h>

tester(int a,...);
main()
{
  int a=0;
  float a1=0.;
  printf("%014.4f\n",a1);
//  scanf("%d",&a);
  if(a)
  {
  tester(4,23,23,42,0);
}
else
{
 tester(4,23,42,10,1,0);

  
}
}
tester(int a,...)
{
 va_list vPtr;
 int num=1;
 va_start(vPtr,a);
 while(1){
   num=va_arg(vPtr,int);
   if(num)
   printf("%4d\n",num);
   else 
     break;
 }
}