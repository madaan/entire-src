//shree ganesh
#include<iostream>
#include<conio.h>
#include<math.h>
#include "bigd.h"
#include "bigdigits.h"
#include "bigdtypes.h"
#define ul unsigned long
#include<windows.h>
#include<stdio.h>
#include<graphics.h>
using namespace std;
class encrypt;
class rsa
{
    //variables to calculate p and q
    long long int n,p,q,primes[100];
    long long int p_cnt;
    //the public key
    long long int e;
    //the private key
    long long int d;
public:
    void calc_prime(); //calculates primes in the neighbourhood of sqrt(n)
    void decide_pq();  //assigns appropriate values to p and q
    void public_key(); //generates public key
    long long int euclidean(long long int ,long long int);//euclidean algo:calculates gcd
    void private_key();//generates private key
    void display();
    friend class encrypt;
};
/*
  class encrypt
  {
        char * message;
        int l;
        public:
               encrypt()
               {
                        cout<<"enter the message to be encrypted ";

   */
void rsa::calc_prime()
{
    //this function calculates two primes around the desired key i.e N
    //in our case N should be ATLEAST 17575 (i.e..fo case ZZZ )
    long long int f;
    long long int t,t2;//array to store primes.
    p_cnt=0;
    cout<<"enter the min for n\n";
    cin>>n;
    t=(long long int)sqrt(n);

    for( long long int i=(t-50); i<=(t+50); i++)
    {
        f=1;
        if(i%2!=0)
            if(i%3!=0)
                if(i%5!=0)
                    if(i%7!=0)
                    {
                        f=0;
                        t2=(long long int)sqrt(i);//check for prime
                        for(long long int j=2; j<=t2; j++)
                        {

                            if(i%j==0)
                            {
                                f=1;//not prime
                                break;
                            }

                        }
                    }
        if(!f)
        {
            primes[p_cnt++]=i;
        }
    }
    decide_pq();
}//at this point long long int array prime has primes from sqrt(n)-50 to sqrt(n) + 50
void rsa::decide_pq()
{
    for(long long int i=0; i<p_cnt; i++)
    {
        cout<<primes[i]<<" ";
    }

    for(long long int k=0; k<(p_cnt-1); k++)
    {

        if((primes[k]*primes[k+1])>n)
        {
            cout<<"p= "<<p<<"q= "<<q<<"\n";
            p=primes[k];
            q=primes[k+1];
            break;
        }
    }
}

void rsa::display()
{
    cout<<"shree ganesh\n";
    char temp1[100],temp2[100];
    initwindow(1368,1000);
    setcolor(4);
    sprintf(temp1,"PUBLIC  KEY : ( %lld ,%lld)\n",n,e);
    sprintf(temp2,"PRIVATE KEY : ( %lld ,%lld)\n",n,d);
    //cout<<"p="<<p<<"\n"<<"q="<<q<<"\n"<<"n="<<n<<"\n"<<"e="<<e<<"\n"<<"d="<<d<<"\n";
    //MessageBox(0,temp1,"sgb2",MB_OK);
    //MessageBox(0,temp2,"sgb3",MB_OK);
    settextstyle(3,0,5);
    outtextxy(100,100,"KEYS GENERATED! ");

    delay(2000);
    settextstyle(6,0,4);
    delay(1000);
    outtextxy(200,200,temp1);
    delay(1000);
    outtextxy(200,400,temp2);
}
void rsa::public_key()
{
    long long int a;
    for(long long int i=3; i<100; i++)
    {
        a=(euclidean((p-1),i)*euclidean((q-1),i));//condition that e should not be a factor of p-1 and q-1;
        if(a==1)
        {
            e=i;
            break;
        }
    }
}
long long int rsa::euclidean(long long int a,long long int b)
{
    long long int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void rsa::private_key()
{
    long long int f=0,i=3,pq=((p-1)*(q-1)),x;
    while(!f)
    {
        x=(i*e);
        if(x>pq)
        {
            if(x%pq==1)
            {
                d=i;

                f=1;
            }
        }
        i++;
    }
}




main()
{
    int gd=DETECT,gm;
//     initwindow(800,600);

    rsa r;
    MessageBox(0,"Generating Keys For n=17575\n","sgb1",MB_OK);
    r.calc_prime();
    r.public_key();
    r.private_key();

    r.display();

    getch();
}
