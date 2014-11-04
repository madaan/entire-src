#include<bits/stdc++.h>
using namespace std;
#define pb push_back
string str[100009];
int n,graph[26][26]={};
vector < vector < int > > ans;
void foo(int l, int r, int ind)
{
    int start[26],end[26];
    memset(start,-1,sizeof(start));
    memset(end,-1,sizeof(end));
    for(int i=0; i<26; i++)
        for(int j=l; j<=r; j++)
            if(str[j][ind]==(char)('a'+i))
            {
                if(start[i]==-1)start[i]=j;
                end[i]=j;
            }
    for(int i=0; i<26; i++)
        for(int j=0; j<26; j++)
        {
            if(start[i]==-1 || start[j]==-1 || i==j)continue;
            if(start[j]>end[i])graph[i][j]=1;
            else if(start[i]>end[j])graph[j][i]=1;
        }
    for(int i=0; i<26; i++)
        if(start[i]!=-1)foo(start[i],end[i],ind+1);
}
void toposort()
{
    int count[26]={};
    vector < int > cur;
    for(int i=0; i<26; i++)
    {
        int flag=0;
        for(int j=0; j<26; j++)
            if(graph[j][i])flag=1,count[i]++;
        if(flag==0)
            cur.pb(i);
    }
    while(1)
    {
        vector < int > ncur;
        if(cur.empty())break;
        ans.pb(cur);
        for(int i=0; i<cur.size(); i++)
            for(int j=0; j<26; j++)
                if(graph[cur[i]][j])
                {
                    graph[cur[i]][j]=0,count[j]--;
                    if(count[j]==0)ncur.pb(j);
                }
        cur.clear();
        for(int i=0; i<ncur.size(); i++)
            cur.pb(ncur[i]);
    }
}
int main()
{
    int flag[26]={};
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> str[i];
        for(int j=0; j<str[i].length(); j++)
            flag[str[i][j]-'a']++;
    }
    foo(0,n-1,0);
    /*    for(int i=0; i<26; i++)
          for(int j=0; j<26; j++)
          if(graph[i][j])
          cout << (char)(i+'a') << " -> "<< (char)(j+'a') << endl; */
    toposort();
    for(int i=0; i<ans.size(); i++,cout<<endl)
    {
        sort(ans[i].begin(),ans[i].end());
        for(int j=0; j<ans[i].size(); j++)
            if(flag[ans[i][j]])
                cout << (char)(ans[i][j]+'a');
    }
    return 0;
}
