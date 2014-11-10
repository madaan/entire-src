//sg
# include<iostream>
# include<string.h>
//on Linux ,your string was conflicting with the inbuilt string class,so i have renamed it to String
using namespace std; //required
class strcount
{
    char * str;
public:
    static int count;
    strcount(char* s)
    {
        int length=strlen(s);
        str=new char[length+1];
        strcpy(str,s);
        count++;  //should increment count
    }
    ~ strcount()  //operation legal only in destructor
    {
        delete str;
    }
    char * getStr()
    {
        return str;
    }
};
int strcount::count=0; //required
class String
{
private:
    strcount* psc;
public:
    String()
    {
        psc=new strcount("");
    }
    String(char* s)
    {
        psc=new strcount(s);
    }
    String(String& s)
    {
        cout<<"\ncopy constructor";
        psc=s.psc;
        (psc->count)++;
    }
    ~String()
    {
        if((psc->count)==1) //syntax
            delete psc;
        else
            (psc->count)--; //2 errors
    }
    void display()
    {
        cout<<psc->getStr();  //str is private
        cout<<"(addr="<<psc<<")";
    }
    String& operator=(String& s)
    {
        cout<<"\nto err is human"; //to debug,divine
        //delete psc;  why delete our String
        psc=s.psc;  //change the order
        (psc->count)++; //one more variable now referring
        return *this;
    }
};
int main() //c++ ,main must return int
{
    String s1,s2;
    String s3((char *)"this is round2_lvl1");
    cout<<"\ns3=";
    s3.display();
    s1=s2=s3;
    cout<<"\ns1=="; //print the extra equal
    s1.display();
    cout<<"\ns2==";//print the extra equal
    s2.display();
}//end

/* Output on my PC
 * s3=this is round2_lvl1(addr=0x91b8048)
to err is human
to err is human
s1==this is round2_lvl1(addr=0x91b8048)
s2==this is round2_lvl1(addr=0x91b8048)
the addresses will vary ,as you said
*/
