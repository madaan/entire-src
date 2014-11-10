//sg
#include<iostream>
#include<string.h>
#define deb
using namespace std;
const int SEED_LENGTH=100;
const int MSG_LENGTH=500;
char * FIRST_LEVEL_CIPHER= {"BDFHJLNPRTVXZACEGIKMOQSUWY"};
class C
{
public:
    int key;
    int iter;
    char msg[100];
    C()
    {
        iter=0;
        key=0;
    }
    void printC()
    {
        cout<<"Key : "<<key<<"\n";
        cout<<msg<<"\n";
    }
    void chain()
    {
        cout<<msg;
    }
    char * const getColumnContent()
    {
        return msg;
    }
};
int partition(char e[],int k,int r)
{
    int i,j,x;
    x=e[k];
    char temp;
    i=k;
    //i+1 to j are all > pivot
    for(j=k+1; j<=r; j++)
    {
        if(e[j]<x)
        {
            i++;
            temp=e[i];
            e[i]=e[j];
            e[j]=temp;
        }
    }
    temp=e[k];
    e[k]=e[i];
    e[i]=temp;
    return i;
}
void quickSortSeed(char e[],int l,int r)
{
    if(l<r)
    {
        int q=partition(e,l,r);
        quickSortSeed(e,l,q-1);
        quickSortSeed(e,q+1,r);
    }
}
int partitionC(C e[],int k,int r)
{
    int i,j;
    C x;
    x=e[k];
    C temp;
    i=k;
    //i+1 to j are all > pivot
    for(j=k+1; j<=r; j++)
    {
        if(e[j].key<x.key)
        {
            i++;
            temp=e[i];
            e[i]=e[j];
            e[j]=temp;
        }
    }
    temp=e[k];
    e[k]=e[i];
    e[i]=temp;
    return i;
}
void quickSortC(C e[],int l,int r)
{
    if(l<r)
    {
        int q=partitionC(e,l,r);
        quickSortC(e,l,q-1);
        quickSortC(e,q+1,r);
    }
}
int getIndex(char * arr,char c,int seedL)
{
    for(int i=0; i<seedL; i++)
    {
        if(arr[i]==c)
        {
            return i;
        }
    }
    return -1;

}
void mapSeed(char * sortedS,char * original,int seedL,int * result)
{
    int SEQ=1,index;
    for(int i=0; i<seedL; i++)
    {
        index=getIndex(original,sortedS[i],seedL);
#ifdef debug
        cout<<"Search for "<<sortedS[i]<<" Returned "<<index<<"\n";
#endif
        result[index]=SEQ++;

    }

}
void encryptC(char * msg,char *CK)
{
    int i=0;
    while(msg[i])
    {
#ifdef debug
        cout<<"Encrypting "<<msg[i]<<"With " <<CK[msg[i]-65]<<endl;
#endif
        msg[i]=CK[msg[i]-65];
        i++;
    }
}
int getIndex(char c,char * str)
{
    int i=0;
    while(str[i])
    {
        if(str[i]==c)
            return i;
        i++;
    }
    return -1;
}
int main()
{
    char seed[100],tempSeed[100],seedL,tmpmsg[MSG_LENGTH];
    char SECOND_LEVEL_CIPHER[27];
    SECOND_LEVEL_CIPHER[0]='\0';
    int CCOUNT,iter,column;
    C * c;
    int result[SEED_LENGTH];
    cout<<"Enter the seed : ";
    cin>>seed;
    strcpy(tempSeed,seed);
    seedL=strlen(seed);
    CCOUNT=seedL;
    c=new C[CCOUNT];
    quickSortSeed(seed,0,seedL-1);
    mapSeed(seed,tempSeed,seedL,result);
    for(int i=0; i<CCOUNT; i++)
    {
        c[i].key=result[i];
    }
    strcpy(tmpmsg,FIRST_LEVEL_CIPHER);
    for(int i=0; tmpmsg[i]; i++)
    {
        column=i%CCOUNT;//get which column
        iter=c[column].iter; //get the loc in the Column buffer
        c[column].msg[iter]=tmpmsg[i];
        c[column].iter++;//update the iterator for the column
    }
    for(int i=0; i<CCOUNT; i++)
    {
        c[i].msg[c[i].iter]='\0';
    }
    quickSortC(c,0,CCOUNT-1);
    for(int i=0; i<CCOUNT; i++)
    {
#ifdef debug
        cout<<c[i].getColumnContent()<<"\n";
#endif
        strcat(SECOND_LEVEL_CIPHER,c[i].getColumnContent());
    }
#ifdef debug
    cout<<SECOND_LEVEL_CIPHER<<"\n";
#endif
    SECOND_LEVEL_CIPHER[26]='\0';
    cout<<"Enter the message : ";
    cin>>tmpmsg;
    encryptC(tmpmsg,SECOND_LEVEL_CIPHER);
    encryptC(tempSeed,FIRST_LEVEL_CIPHER);
    cout<<"\n\nENCRYPTED MESSAGE : "<<tmpmsg<<"\nENCRYPTED SEED : "<<tempSeed;

    return 0;
}
