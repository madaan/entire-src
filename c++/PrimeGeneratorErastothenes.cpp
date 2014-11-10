//sg
//sg
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*
 * function that checks whether a number is
 * prime  or not.
 *
 * return : true or false depending on whether the
 * number is prime.
 */
bool isPrime(long n)
{
    if((n==2)||(n==3)||(n==5)||(n==7))
    {
        return true;
    }
    if((n%2==0)||(n==1)||(n%3==0)||(n%5==0)||(n%7==0))
    {
        return false;
    }

    if((n>10)&&(n%10==5))
    {
        return false;
    }
    long sn=sqrt(n);
    for(int i=2; i<=sn; i++)
    {
        if(n%i==0)
        {

            return false;
        }
    }
    return true;
}
/*
 * Function to prime numbers in a range
 *
 * input :
 * long l : lower limit
 * long u : upper limit
 *
 * return :
 * 	void, the numbers are printed in the
 * 	function itself
 *
 *
 */
void getPrimes(long l,long u)
{
    //some space for time
    long numbers[100000];
    bool check[100000];
    bool found=true;
    long p;
    int j=0,index,uindex=u-l+1;;
    p=l;
    //initialize the arrays
    for(long i=l; i<=u; i++,j++)
    {
        numbers[j]=i;
        check[j]=false;
    }
    //find out the first prime
    while(!isPrime(p))
    {
        p++;
    }

    //start the sieve of erastothenes
    //terminates automatically when there are no more numbers that
    //can be marked
    while(1)
    {
        // 1. start from p
        index=p-l;
        //go p numbers ahead
        index=index+p;
        // 2. mark all the multiples of p
        while(index<uindex)
        {

            if(!check[index])
            {
                check[index]=true;
                //tells whether or not we have an unmarked multiple
                found=true;
            }
            //go to multiple
            index+=p;
        }
        if(!found)
        {
            //no number was checked in this iteration, indicating
            //that all that is left now are primes.
            break;
        }
        found=false;
        //start from the next number after the prime
        index=p-l+1;
        // 3. get the first non marked number now
        while((check[index])&&(index<u))
        {
            index++;
        }
        if(index==u)
        {
            //everyone is marked, no primes
            break;
        }
        p=l+index; //get the number
        //repeat the procedure
    }
    //dump all the numbers that are unchecked

    for(j=0; j<(u-l+1); j++)
    {
        if(!check[j])
            printf("%ld\n",numbers[j]);
    }

}
int main(int argc,char * argv[])
{
    getPrimes(atoi(argv[1]),atoi(argv[2]));
    return 0;
}
