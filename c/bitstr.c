//sg
#include<stdio.h>
main()
{
char astr[11],bstr[6];
int off,substr,cases;
scanf("%d",&cases);
while(cases--)
{
substr=0;
off=0;
scanf("%s%s",astr,bstr);
while(off<6)
{
if((astr[off]==bstr[0])&&(astr[off+1]==bstr[1])&&(astr[off+2]==bstr[2])&&(astr[off+3]==bstr[3])&&(astr[off+4]==bstr[4]))
{
substr=1;
break;
}
off++;
}
if(substr)
puts("1\n");
else
puts("0\n");
}
}
