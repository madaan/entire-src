//sg
#include<iostream>
#include<stdlib.h>
using namespace std;
class TowerOfHanoi
{
public:
//there are 3 pegs : 1 ,2 and 3
void movePegs(int n,int to,int from ,int aux)
{
if(n==1)
{
cout<<"\a\nMoving "<<n<<" pegs from "<<to<<" to "<<from;
return;
}
//first move the first n-1 pegs to auxilary
movePegs(n-1,aux,from,to);
//then move the final peg to the destination
cout<<"\a\nMoving "<<n<<" pegs from "<<to<<" to "<<from;
//finally move the remaining n-1 pegs to the destination using initial 
//destination as the final peg
movePegs(n-1,to,aux,from);
}
};
main(int argc,char * argv[])
{
TowerOfHanoi thoi;
if(argc!=5)
{
cout<<"Usage : ./executable Pegs To From Auxn\n";
return 1;
}
thoi.movePegs(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
cout<<"\n";
}

