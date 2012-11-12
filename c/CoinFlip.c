		//sg
		#include<stdio.h>
		#define HEADS 1
		#define TAILS 2

		int main()
		{
			int
				cases, //total cases
				G,//total games
				I, //initial state
				Q;//1 if heads are required , 2 otherwise 
				
				
			long long int N, //Total coins and rounds
							heads, //resulting heads
							tails;//resulting tails
							//result[]={0,0};	
			scanf("%d",&cases);
			
			while(cases--)
			{
				scanf("%d",&G);
				while(G--)
				{
					heads=tails=0;
					scanf("%d%lld%d",&I,&N,&Q);
					if(N%2==0)
				{
				heads=N>>1;
				tails=N>>1;
				}
			else if(I==HEADS)
			{
				heads=((N+1)>>1)-1;
				tails=(N>>1)+1;
			}
			else
			{
				tails=((N+1)>>1)-1;
				heads=(N>>1)+1;	
			}
					if(Q==HEADS)
					{
						printf("%lld\n",heads);
					}
					else
					{
						printf("%lld\n",tails);
					}
				}
			}
				return 0;
			}
