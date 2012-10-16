#include<stdio.h>
 
#include<stdlib.h>
 
#include<malloc.h>
 
 
 
#define SIZE 26
 
 
 
static int visited[26]={0};
 
static int present[26]={0};
 
 
 
struct graph {
 
int adjm[SIZE][SIZE];
int indegs[SIZE];
 
int outdegs[SIZE];
 
};
 
 
 
void graph_init (struct graph *g)
 
{
 
int i,j;
 
for (i=0;i<SIZE;i++)
 
for (j=0;j<SIZE;j++)
 
g->adjm[i][j]=0;
 
for(i=0;i<SIZE;i++)
 
g->indegs[i]=g->outdegs[i]=0;
 
for(i=0;i<SIZE;i++)
 
visited[i]=present[i]=0;
 
}
 
 
 
void graph_add_edge (struct graph *g, int start, int end)
 
{
 
g->adjm[start][end]+=1;
 
g->indegs[end]++;
 
g->outdegs[start]++;
 
present[start]=1;
 
present[end]=1;
 
}
 
 
 
void graph_dfs(struct graph *g, int index)
 
{
 
int mi=0;
 
for (mi=0;mi<SIZE;mi++)
 
if ( (g->adjm[index][mi]>0 || g->adjm[mi][index]>0) && visited[mi]==0 )
 
{
 
visited[mi]=1;
 
graph_dfs(g,mi);
 
}
 
}
 
 
 
int odds(struct graph *g)
 
{
 
int i,flag=0;
 
for (i=0;i<26;i++)
 
if(present[i]==1)
 
{
 
visited[i]=1;
 
graph_dfs(g, i);
 
break;
 
}
 
for (i=0;i<26;i++)
 
if(present[i]==1 && visited[i]==0)
 
return 0;
 
 
 
for (i=0;i<26;i++)
 
{
 
if (g->indegs[i] - g->outdegs[i] == 1)
 
flag++;
 
else if(g->indegs[i] -g->outdegs[i] == -1)
 
flag++;
 
else if (g->indegs[i]-g->outdegs[i] != 0)
 
return 0;
 
}
 
 
if (flag==2 || flag==0)
 
return 1;
 
return 0;
 
}
 
 
 
int main(int argc, const char *argv[])
 
{
 
int i, j, lines, tests;
 
struct graph *g=(struct graph *)malloc(1*sizeof(struct graph *));
 
char c,f,s;
 
 
for (i=0,scanf("%d",&tests);i<tests;i++)
 
{
 
graph_init(g);
 
for (j=0,scanf("%d",&lines),getchar();j<lines;j++)
 
{
 
f=getchar();
 
while ((c=getchar())!='\n')
 
s=c;
 
graph_add_edge(g, f-'a', s-'a');
 
}
 
printf("%s\n",(odds(g)==0?"The door cannot be opened.":"Ordering is possible."));
}
 
return 0;
 
}
