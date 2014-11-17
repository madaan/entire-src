//sg
#include<stdio.h>
#include<map>
#include<string>
#include<bits/stdc++.h>
#define debu
using namespace std;
// A tour is made up of several trips
class Trip
{
public:
    string to,from;
    int cost;
    Trip * next;
    Trip * prev;
    Trip(string from,string to,int cost)
    {
        this->to=to;
        this->from=from;
        this->cost=cost;
        next=prev=NULL;
    }
    void details()
    {
        printf("%s-%s ",from.c_str(),to.c_str());
#ifdef debug
        if(next!=NULL)
        {
            printf("\nNext : %s",next->from.c_str());
        }
        if(prev!=NULL)
        {
            printf("\nPrev : %s",prev->from.c_str());
        }
#endif
    }
    Trip()
    {
    }
};
int main()
{
    int trips;
    string to,from;
    Trip temp,*iter=NULL;
    char to_t[550],from_t[550];
    int cost,cases;
    map<string,Trip> tour;
    map<string,Trip>::iterator it;
    scanf("%d",&cases);
    for(int tt = 1; tt <= cases; tt++) {
        printf("Case #%d: ", tt);
        scanf("%d",&trips);
        //read all the trips
        while(trips--)
        {
            scanf("%s", from_t);
            scanf("%s", to_t);
            from=from_t;
            to=to_t;
            tour[from]=Trip(from,to,0);
        }
        //create the list
        for(it=tour.begin(); it!=tour.end(); it++)
        {
            Trip * temp=&((*it).second);
            //temp->next should store the next Trip
            if(tour.count(temp->to))
            {
                temp->next=&((tour.find(temp->to))->second);
                //also make the reverse connection
                (temp->next)->prev=(temp);
#ifdef debug
                printf("\nAdding %s -> %s",temp.from.c_str(),(temp.next)->from.c_str());
                printf("\nAdding %s behind %s",((temp.next)->prev)->from.c_str(),(temp.next)->from.c_str());
#endif
            }
        }
        //find the begining of the list :
        iter=&((tour.begin())->second);
        while(iter->prev)
        {
            iter=iter->prev;
        }
        //we have the start of the list,dump one by one
        cost=0;
        while(iter)
        {
            iter->details();
            cost+=iter->cost;
            iter=iter->next;
        }
        //printf("\n%d$",cost);
        tour.clear();
        cout << "\n";
    } //while cases exhaust
    return 0;
}
