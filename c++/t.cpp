#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc,char *argv[])
{
  if(argc == 1)
  {
     cout<<"No arguments.You should run this program in terminal with several arguments."<<endl;
     exit(1);
  }
  else
  { 
    cout<<"The arguments you put are:"<<endl;
      for(int i=1;i<argc;i++)
          cout<<argv[i]<<endl;
      cin.get();
      return 0;
  }
}
