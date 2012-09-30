//sg
#include<pthread.h>
#include<iostream>
void* func(void * n)
{
std::cout<<"\nHello from "<<*(static_cast<int *>(n))<<"\n";
for(long long int i=0;i<1000000000;i++)
{
//	std::cout<<"Running : "<<*(static_cast<int *>(n))<<"\n";
}
return NULL;
}
int main()
{
	pthread_t id[10];
	void * exs;
	int n=4;
	for(int i=0;i<10;i++)
	{
	
	n++;
	pthread_create(&id[i],NULL,func,(&i));
	pthread_join(id[i],&exs);
	}
	for(int i=0;i<10;i++)
	{
	//pthread_join(id[i],&exs);
}
	return 0;
}
