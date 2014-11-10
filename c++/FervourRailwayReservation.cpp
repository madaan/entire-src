//sg
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#include<string.h>
using namespace std;
int ticketNum; //uniqueId
void printMargins()
{
    cout<<"\n\n\t#######FERVOUR 2012##########\n\n\n";

}
void displayMenu()
{
    printMargins();
    cout<<"\t\a\a\aWelcome!\n";
    cout<<"\t1.Book A Ticket\n\n";
    cout<<"\t2.Cancel Your Ticket (Record Will Be Deleted)\n\n";
    cout<<"\t3.Query Ticket Details\n\n";
    cout<<"\t4.Invalidate Ticket (Record Will Be Deleted,Contact Admin For Revoking)\n\n";
    cout<<"\t5..Exit\n\n\tEnter Your Choice : ";
}
void readUID()
{
    ifstream fi;
    fi.open("ticketNum.txt",ios::in);
    fi>>ticketNum;
    fi.close();
}
void writeUID()
{
    ofstream fi;
    fi.open("ticketNum.txt",ios::out);
    fi<<ticketNum;
    fi.close();
}
class Person
{
public:
    char name[100];
    int age;
    char gender;
    char date[100];
    char trainName;
    long ticketNum;
    char src[100],dest[100];
    bool valid;
    Person(char const *  name,int age,char gender,char date[100],char trainName,long ticketNum,char src[100],char  dest[100])
    {
        strcpy(this->name,name);
        this->age=age;
        strcpy(this->date,date);
        strcpy(this->dest,dest);
        this->gender=gender;
        this->ticketNum=ticketNum;
        this->trainName=trainName;
        strcpy(this->src,src);
        valid=true;
    }
    Person()
    {
    }
    void displayDetails()
    {

        cout<<"\n\t___________________________";
        cout<<"\n\t1) Name : "<<name;
        cout<<"\n\t2) Age : "<<age;
        cout<<"\n\t3) Sex : "<<gender;
        cout<<"\n\t4) Date of booking : "<<date;
        cout<<"\n\t5) Train name : "<<trainName;
        cout<<"\n\t6) Unique ticket number : "<<ticketNum;
        cout<<"\n\t7) Source place : "<<src;
        cout<<"\n\t8) Destination place : "<<dest;
        cout<<"\n\t___________________________\n";

    }
};
class BookingHandler
{
    fstream f;
public:
    void searchAndCancel(long target)
    {
        Person p;
        int numRec=searchAndDisplay(target);
        if(numRec!=-1)
        {
            printMargins();
            cout<<"\n\nInvalidating The Record...";
            //get the record
            ifstream irec("sgrecords.dat",ios::binary|ios::in);
            irec.seekg(sizeof(p)*(numRec));
            irec.read((char *)&p,sizeof(p));
            //now invalidate it ,with leaving the possibility of revalidation
            p.valid=false;
            ofstream orec("sgrecords.dat",ios::binary|ios::out);
            orec.seekp(sizeof(p)*(numRec));
            orec.write((char *)&p,sizeof(p));

            cout<<"\n\nInvalidation Successful!";
            irec.close();
            orec.close();


        }

    }
    void searchAndDelete(long target)
    {

        Person p;
        int i=1;
        cout<<"\nSearching...\n";
        int numRec=searchAndDisplay(target);
        if(numRec!=-1)
        {

            cout<<"\nRecord Found,Record Number "<<numRec<<" Will Now Be Deleted...\n";
            ifstream irec("sgrecords.dat",ios::binary);
            ofstream orec("sgrecordstemp.dat",ios::binary|ios::trunc);

            while(!irec.eof()) //print all but this record
            {

                if(i==numRec)
                {
                    i++;
                    //irec.read((char *)&p,sizeof(p));  //just advance the pointer
                    printf("\nAt:%d",irec.tellg());
                    irec.read((char *)&p,sizeof(p));  //just advance the pointer
                    irec.read((char *)&p,sizeof(p));  //just advance the pointer

                    // irec.seekg((sizeof(p)*numRec));
                    printf("\nAt:%d",irec.tellg());
                    if(irec.eof())
                    {
                        cout<<"I ENDED TOO!";
                    }
                    cout<<"Skipping : ";
                    //p.displayDetails();
                    continue;

                }
                cout<<"Writing "<<i<<"\n";
                irec.read((char *)&p,sizeof(p));
                p.displayDetails();
                orec.write((char *)&p,sizeof(p));
                i++;
            }
            irec.close();
            orec.close();
            remove("sgrecords.dat");
            rename("sgrecordstemp.dat","sgrecords.dat");


        }
    }

    int searchAndDisplay(long target)
    {
        int recordNumber=0; //after How Many Records was the required record found,to be used by searchAndCancel()
        Person p;
        bool found=false;
        f.open("sgrecords.dat",ios::binary|ios::in);
        if(!f)
        {
            perror("Error Handling Files!\nProgram Will Now Exit");
            exit(1);
        }
        while(!f.eof())
        {
            f.read((char *)&p,sizeof(p));
            recordNumber++;
            if((p.ticketNum==target)&&(p.valid)) //record found + valid
            {
                printMargins();
                cout<<"\n\n\n\t### RECORD FOUND ###";
                p.displayDetails();
                cout<<"\n\n";
                found=true;
                break;
            }
            else if((p.ticketNum==target)&&(!p.valid)) //record found but invalid
            {
                printMargins();
                cout<<"\t\t\nSorry ,The Record Was Found In Our Database,But The Booking Was Cancelled!\nPlease Contact 9989-913333 for support\nThank You!\n";
                found=true;
                break;

            }


        }
        if(!found)
        {
            printMargins();
            cout<<"\t\t\nSorry ,The Record Was Not Found In Our Database,Please Contact 9989-913333 for support\nThank You!";
            recordNumber=-1;


        }

        f.close();
        return recordNumber;
    }
    void bookATicket()
    {
        char sure='f';
        Person p;
        while(sure=='f')
        {
            p=readDetails();
            p.displayDetails();
            cout<<"Are You Sure You Want To Book The Ticket? ( \' f \' to re-enter details,any other character to continue!)\n";
            cin>>sure;
            if(sure=='f')
                continue;
            else
                break;
        }
        //write Details
        writeDetails(p);
        printMargins();
        cout<<"\n\n####		Ticket Booked!		###\n\n";
    }

    //need not call these functions from outside
private:
    void writeDetails(Person p)
    {
        f.open("sgrecords.dat",ios::app|ios::binary|ios::out|ios::ate);
        if(!f)
        {
            perror("Error Handling Files!\nProgram Will Now Exit");
            exit(1);
        }
        //write the object
        f.write((char*)&p,sizeof(p));
        f.close();
    }
    Person readDetails()
    {
        Person p;
        bool genderOk=false,ageok=false;
        cout<<"\nEnter Name :";
        cin.ignore();
        gets(p.name);
        while(!ageok)
        {
            cout<<"\nEnter Age :";
            cin>>p.age;
            if((0<p.age)&&(p.age<110))
            {
                ageok=true;
            }
        }
        while(!genderOk)
        {
            cout<<"\nEnter Sex (M/F):";
            cin>>p.gender;
            if((p.gender=='m')||(p.gender=='M')||(p.gender=='F')||(p.gender=='f'))
                genderOk=true;


        }
        cout<<"\nEnter Source place :";
        cin>>p.src;
        cout<<"\nEnter Destination place :";
        cin>>p.dest;


        //_________AUTOMATIC ASSIGNMENTS BEGIN_______________
        p.valid=true;
        //assign UID
        p.ticketNum=ticketNum++;
        //assign date automatically
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        sprintf(p.date,"%d/%d/%d", (now->tm_year + 1900),(now->tm_mon + 1),now->tm_mday);

        //assign a train ,randomly
        int r=(now->tm_sec)%3;
        switch(r)
        {
        case 0:
            p.trainName='a';
            break;
        case 1:
            p.trainName='b';
            break;
        case 2:
            p.trainName='c';
            break;
        default:
            p.trainName='c';
            break;
        }
        return p;
    }
};
int main()
{
    int choice;
    long ticketToCancel,ticketToQuery;
    BookingHandler b;
    //read the current ticketNum at the outset
    readUID();
    Person p;
    while(true)
    {
        displayMenu();
        //read input
        cin>>choice;
        switch(choice)
        {
        case 1:
            b.bookATicket();
            writeUID(); //update UID
            break;
        case 2:
            cout<<"\nEnter The Ticket Number To Cancel : ";
            cin>>ticketToCancel;
            b.searchAndDelete(ticketToCancel);
            break;
        case 3:
            cout<<"\nEnter The Ticket Number To Query : ";
            cin>>ticketToQuery;
            b.searchAndDisplay(ticketToQuery);
            break;

        case 4:
            cout<<"\nEnter The Ticket Number To Cancel : ";
            cin>>ticketToCancel;
            b.searchAndCancel(ticketToCancel);
            break;
        case 5:
            exit(0);

        default:
            cout<<"\nWrong Choice";
            continue;
        }
    }
    //write the final value of UID now

    return 0;
}
