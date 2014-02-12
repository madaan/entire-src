#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;
int K,N,M;
const int INF= 1000000000;
int cost[51],value[51];
int dp[101][22][51][51];
int nxt[101][22][51];
int rec(int bud,int days,int pre,int cnt)
{
    //printf("rec(%d, %d, %d, %d)\n", bud, days, pre, cnt);
    if ( bud < 0)return -INF;
    if ( bud==0 && days>0)return -INF;
    if ( days==0)return 0;
    int &ret = dp[bud][days][pre][cnt];
    if ( ret!=-1)return ret;
    ret = -INF;
    int mx = -1;
    for ( int i=0;i<N;i++){
        if ( i!=pre){
            int v = rec(bud-cost[i],days-1,i,1);
            if ( v!=-INF){
                if ( v + value[i] > ret ){
                    ret = v + value[i];
                    mx = i;   
                }
            }
        }
        else{
            int val = value[i]>>1;
            if ( cnt > 1 )val = 0;
            int v = rec(bud-cost[i],days-1,i,cnt+1);
            if ( v!=-INF){
                if ( v + val > ret ){
                    ret = v + val;
                    mx = i;
                }   
            }
        }   
    }
    nxt[bud][days][pre] = mx;
    return ret;
}
 
void retrace(int bud,int days,int pre)
{
    if ( days==0){
        printf("\n");
        return;   
    }   
    int n = nxt[bud][days][pre];
    printf("%d ",n);
    retrace(bud-cost[n],days-1,n);
}
 
int main()
{
    while(scanf("%d%d%d",&K,&N,&M),K+N+M>0){
        for(int i=1;i<=N;i++) 
            scanf("%d%d",&cost[i],&value[i]);
        for(int i=1;i<=N;i++)
            value[i]=2*value[i];
        
        memset(dp,-1,sizeof(dp));
        
        int ans = -INF;
        int p = -1;
        for ( int i=1;i<=M;i++){
            int v = rec ( i,K,0,N+1);
            if ( ans < v ){
                ans = v;
                p =  i;
            }
        }
        if ( ans==-INF)printf("0.0\n\n");
        else{
            printf("%.1lf\n",((double)ans)/2.0);
            retrace(p,K,N+1);   
        }
                
        
    }
return 0;
}
