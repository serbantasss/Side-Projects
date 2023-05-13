#include <bits/stdc++.h>
using namespace std;
int val[16005];
vector<int> adc[16005];
bool viz[16005];
int dfs(int nod)
{
    viz[nod]=1;
    for(int i=0;i<adc[nod].size();++i)
        if(!viz[adc[nod][i]])
            val[nod]+=dfs(adc[nod][i]);
    if(val[nod]<0)
        return 0;
    return val[nod];
}
int main()
{
    freopen("asmax.in","r",stdin);
    freopen("asmax.out","w",stdout);
    int n,maxx=-100000;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&val[i]);
        if(val[i]>maxx)
            maxx=val[i];
    }
    for(int i=1;i<n;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        adc[x].push_back(y);
        adc[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;++i)
        if(val[i]>maxx)
            maxx=val[i];
    if(n>1)
        printf("%d",maxx);
    return 0;
}