//sg
#include<iostream>
#include<string.h>
using namespace std;
class CyclicString
{
    int len;
    char  str[99];
    void strrev(char str[],int l,int r)
    {
        int rightOff=0;
        for(int i=l; i<((r-l+1)/2)+l; i++)
        {
            str[i]^=str[r-rightOff];
            str[r-rightOff]^=str[i];
            str[i]^=str[r-rightOff];
            rightOff++;
        }
    }
public :
    CyclicString(char str[])
    {

        len=strlen(str);
        strcpy(this->str,str);
    }
    void cycleThrough(char ** result)
    {
        int left=0;
        for(int i=0; i<len; i++)
        {
            strcpy(result[i],str);
            strrev(result[i],0,i);
            strrev(result[i],i+1,len-1);
            strrev(result[i],0,len-1);
            left++;
        }
    }
    void putString()
    {
        cout<<str<<"\n";
    }
    int getLength()
    {
        return len;
    }
};
int main(int argc,char *argv[])
{
    CyclicString cstr(argv[1]);
    char * result[200];
    int l=strlen(argv[1]);
    for(int i=0; i<l; i++)
    {
        result[i]=new char[200];
    }
    cstr.cycleThrough(result);
    cout<<endl;
    for(int i=0; i<cstr.getLength(); i++)
    {
        cout<<result[i]<<"\n";
    }
    return 0;
}
