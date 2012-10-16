//sg
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class NumberReader
{
	char filename[200];
	int * arr;
	fstream f;
	int numEle;
	public:
	NumberReader(char * const filename,int numEle)
	{
		f.open(filename,ios::in);
		if(!f.good())
		{
			cout<<"Error Opening File\n";
			exit(0);
		}
		arr=new int[numEle];
		strcpy(this->filename,filename);
		this->numEle=numEle;
		readNumbers();
	}
	private:
	void readNumbers()
	{
		for(int i=0;i<numEle;i++)
		{
			
			f>>arr[i];
			
		}
	}
	public:
	int * getArray()
	{
		return arr;
	}
	void printNumbers()
	{
		for(int i=0;i<numEle;i++)
		{
			
		cout<<arr[i]<<endl;
			
		}
	}
	
};


