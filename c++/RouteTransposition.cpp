//sg
#include<iostream>
#include<string.h>
using namespace std;
const int MSG_LENGTH=150;
int power2(int x)
{
    --x;
    x=x|(x>>1);
    x=x|(x>>2);
    x=x|(x>>4);
    x=x|(x>>8);
    x=x|(x>>16);
    ++x;
    return x;
}
void storeInMatrix(char * msg,char  matrix[][4],int rows)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<4; j++)
        {
            matrix[i][j]=msg[i*4+j];

        }
    }
}
void dumpMatrix(char  matrix[][4],int rows)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool movable(bool visited[][6],int i,int j,int D)
{
    int DOWN=0,LEFT=1,UP=2,RIGHT=3;
    switch(D)
    {
    case DOWN:
        if(visited[i][j])
        }
    void calcRoute(int route[][2],nr,4)
    {
        //scan all the elements
        int rc=0;
        int DOWN=0,LEFT=1,UP=2,RIGHT=3,dir;
        bool finish;
        bool visited=new bool[nr+2][4+2];
        for(int i=0; i<nr; i++)
        {
            for(int j=0; j<nc; j++)
            {
                visited[i][j]=false;
            }
        }
        for(int i=0; i<nr; i++)
        {
            visited[i][0]=true;
            visited[i][4]=true;
        }

        D=DOWN;
        int i,j;
        i=0,j=4;
        while(!finish)
        {
            if(D==DOWN)
            {
                while(!visited[i][j])
                {
                    route[rc][0]=i++;
                    route[rc][1]=j;
                    rc++;
                }
                if(!visited[i][j-1])
                {
                    D=LEFT;
                    j=j-1;
                }
                else
                {
                    break;

                }
            }

        }
        if(D==UP)
        {
            while(!visited[i][j])
            {
                route[rc][0]=i--;
                route[rc][1]=j;
                rc++;
            }
            if(!visited[i][j+1])
            {
                D=RIGHT;
                j=j+1;
            }
            else
            {
                break;

            }
        }
        if(D==LEFT)
        {
            while(!visited[i][j])
            {
                route[rc][0]=i++;
                route[rc][1]=j;
                rc++;
            }
            if(!visited[i][j-1])
            {
                D=LEFT;
            }
            else
            {
                break;

            }
        }
        if(D==DOWN)
        {
            while(!visited[i][j])
            {
                route[rc][0]=i++;
                route[rc][1]=j;
                rc++;
            }
        }
    }

    for(int i=0; i<nr; i++)
    {
        route[rc][0]=i;
        route[rc][1]=i*4+3;
        rc++;
    }
    //
}
void routeTransposition()
{
    char msg[MSG_LENGTH];
    char matrix[32][4];
    int l;
    int np;
    cout<<"Enter the message : ";
    cin>>msg;
    l=strlen(msg);
    if(l&1) //l not power of 2
    {

        np=power2(l);
        for(int i=l; i<np; i++)
        {
            msg[i]='_';
        }
        msg[np]='\0';
    }
    //cout<<msg<<"\n";

    storeInMatrix(msg,matrix,np/4);
    //dumpMatrix(matrix,np/4);
}
int main()
{
    routeTransposition();

}
