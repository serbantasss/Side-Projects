#include <bits/stdc++.h>
using namespace std;
bool f[100005];
int ans[100005],sol;
vector<int> adiac[100005];
void dfs(int x)
{
    //ans[x]=++sol;
    f[x]=1;
    for(int i=0;i<adiac[x].size();++i)
        if(!f[adiac[x][i]])
            dfs(adiac[x][i]);
}
void dfs1(int x)
{
    ans[x]=++sol;
    f[x]=1;
    for(int i=0;i<adiac[x].size();++i)
        if(!f[adiac[x][i]])
            dfs1(adiac[x][i]);
}
int main()
{
    freopen("zapada.in","r",stdin);
    freopen("zapada.out","w",stdout);
    int n,m,i,j,a,b,start;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&a,&b);
        adiac[b].push_back(a);
    }
    for(i=1;i<=n;++i)
        if(!f[i])
            dfs(i),start=i;
    for(i=1;i<=n;++i)
        f[i]=0;
    dfs1(start);
    for(i=1;i<=n;++i)
        printf("%d ",ans[i]);
    return 0;
}