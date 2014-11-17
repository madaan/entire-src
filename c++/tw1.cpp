//sg
#include<iostream>
#include<stdlib.h>
using namespace std;
class Country
{
    int ipodCount;
    int tspCost;
    int cost;
    char * name;
public:
    Country(int cost,int tspCost,char * name)
    {
        ipodCount=100;
        this->tspCost=tspCost;
        this->cost=cost;
        this->name=name;
    }
    int status()
    {
        int temp=ipodCount;
        ipodCount=100;
        return temp;
    }
    int calCost(int units)
    {
        int tenCounts;
        if(units%10)
        {
            tenCounts=units/10+1;
        }
        else
        {
            tenCounts=units/10;
        }
        if(ipodCount<units)
        {
            return -1;
        }
        ipodCount=ipodCount-units;
        return (units*cost+tenCounts*tspCost);
    }
    void setCost(int cost)
    {
        this->cost=cost;
    }
    void getCost()
    {
        cout<<"Cost is "<<cost<<endl;
    }
    char * getName()
    {
        return name;
    }
};
class IPString
{
public:
    char ipstring[100];
    char country[100];
    char countryCode;
    int units;
    void explode(char c)
    {
        int i=0,j=0;
        char temp[10];
        countryCode=ipstring[i];
        while(ipstring[i]!=c)
        {
            country[i]=ipstring[i];
            i++;
        }
        country[i]='\0';
        i++;//skip the :
        while(ipstring[i])
        {
            temp[j++]=ipstring[i++];
        }
        temp[j]='\0';
        units=atoi(temp);
    }
    friend istream & operator >>(istream &i,IPString& istr);
};
istream& operator >>(istream &i,IPString& istr)
{
    i>>istr.ipstring;
    istr.explode(':');
    return i;
}
class Decider
{
public:
    static int CostCalculator(Country& bz,Country& ag,char orderFrom,int units)
    {
        int cost=0;
        int buyb,buya;
        if(orderFrom=='B')
        {
            if(units>100) //only 1 option
            {
                buya=100;
                buyb=units-100;
            }
            else if(((units%10)==9)||(units%10==0)) //buy all from ag
            {
                buya=units;
                buyb=0;
            }
            else //buy only in multiple of 10 from ag, rest from bz
            {
                buyb=units%10;
                buya=units-buyb;
            }
            cost=ag.calCost(buya)+bz.calCost(buyb);
            return cost;
        }
        if(orderFrom=='A') //argentina has cheapest ipods, buy all unless you run out
        {
            if(units<=100)
            {
                buya=units;
                buyb=0;
            }
            else
            {
                buya=100;
                buyb=units-100;
            }
            cost=ag.calCost(buya)+bz.calCost(buyb);
            return cost;
        }
    }
};
int main()
{
    Country b(100,400,"Brazil");
    Country a(50,400,"Argentina");
    int cases;
    cin>>cases;
    IPString ipstr;
    while(cases--)
    {
        cin>>ipstr;
        cout<<(Decider::CostCalculator(b,a,ipstr.countryCode,ipstr.units))<<":";
        cout<<b.status()<<":"<<a.status()<<endl;
    }
    return 0;
}
