//sg
#include<fstream>
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
main()
{
    int d;
    ofstream of("sgw.csv");
    char * dept[]= {"CSE","IT","ICE","ECE","EEE"};
    srand(time(NULL));
    for(int i=0; i<100; i++)
    {
        d=rand()%5;
        of<<i<<","<<dept[d]<<"\n";
    }
}
