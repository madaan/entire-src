		//sg
		#include<stdio.h>
		#define NOT_FOUND -1
		#define FOUND 1
		#define usecache
		#define PRIME 999997
		//long long cache[100]={0,1,2,3}; //rest set to 0
		long long cache[1000000][2];
		int cacheCount;
		/* 
		 * Linear search : costly
		int searchCache(long long arg)
		{
			int i=0;
			for(;i<cacheCount;i++)
			{
				if(cache[i][0]==arg)
				{
					return i;
				}
			}
			return NOT_FOUND;
		}
			int inCache(long long num,long long res)
		{
			
			
			if(cacheCount>99990)
			{
				cacheCount=0;
			}
			if(searchCache(num)==NOT_FOUND)
			{
				cache[cacheCount][0]=num;
				cache[cacheCount][1]=res;
				cacheCount++;
				return cacheCount-1;
			}
			return -1;
			
		}
		*/
		//using hash table
		int searchCache(long long arg)
		{
			int pos=arg%PRIME;
			if(cache[pos][0]==arg)
			{
				return pos;
			}
			return NOT_FOUND;
		}
		int inCache(long long num,long long res)
		{
			if(searchCache(num)==NOT_FOUND)
			{
				int pos=num%PRIME;
				cache[pos][0]=num;
				cache[pos][1]=res;
				return pos;
			}
			return NOT_FOUND;
		}
		long long byteCoins(long long x)
		{
			long long div;
			int pos;
			if(x<12)
			{
				return x;
			}
			if(x==12)
			{
				return 13;
			}
	
			#ifdef usecache
			if((pos=searchCache(x))!=NOT_FOUND)
			{
				return cache[pos][1];
			}
			#endif
			div=byteCoins(x>>1)+byteCoins(x/3)+byteCoins(x>>2);
			#ifdef usecache
			pos=inCache(x,(x>div?x:div));
			return cache[pos][1];
			#endif
			#ifdef nocache
			return (x>div?x:div);
			#endif
		}
		int main()
		{
		long long num,conversion;
		while(scanf("%lld",&num)!=EOF)
		{
				conversion=byteCoins(num);
				printf("%lld\n",conversion);
		}
		return 0;
		}
