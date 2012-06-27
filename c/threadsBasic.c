//sg
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#define NO_OF_THREADS 15
void * threadHello(void * i)
{
printf("\nI am thread number %d",*(int *)i);

}
main()
{
int i;
pthread_t myt[NO_OF_THREADS];
for(i=0;i<NO_OF_THREADS;i++)
{
pthread_create(&myt[i],NULL,threadHello,(void *)&i);
printf("\nCreated Thread Number %d",i);
}
}
