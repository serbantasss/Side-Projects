#include <bits/stdc++.h>
using namespace std;
int v[200005],cost[200005],n;
bool viz[200005];
void dfs(int nod)
{
    viz[nod]=1;
    if(!viz[v[nod]] || (cost[v[nod]]>cost[nod]+1))
    {
        cost[v[nod]]=cost[nod]+1;
        dfs(v[nod]);
    }
    if((!viz[nod+1] && nod<n) ||(cost[nod+1]>cost[nod]+1))
    {
        cost[nod+1]=cost[nod]+1;
        dfs(nod+1);
    }
    if((!viz[nod-1] && nod>1) ||(cost[nod-1]>cost[nod]+1))
    {
        cost[nod-1]=cost[nod]+1;
        dfs(nod-1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&v[i]);
    dfs(1);
    for(int i=1;i<=n;++i)
        printf("%d ",cost[i]);
    return 0;
}