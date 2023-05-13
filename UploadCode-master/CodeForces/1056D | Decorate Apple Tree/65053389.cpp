#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>G[100005];
int viz[100005],frunze[100005];
void dfs(int nod)
{
    viz[nod]=1;
    bool ok=1;
    for(int i=0;i<G[nod].size();++i)
        if(!viz[G[nod][i]])
            ok=0,dfs(G[nod][i]);
    if(ok)
        frunze[nod]=1;
    else
        for(int i=0;i<G[nod].size();++i)
            frunze[nod]+=frunze[G[nod][i]];
}
int main()
{
    int n,i,nod;
    scanf("%d",&n);
    for(i=1;i<n;++i)
    {
        scanf("%d",&nod);
        G[nod].push_back(i+1);
        G[i+1].push_back(nod);
    }
    dfs(1);
    sort(frunze+1,frunze+n+1);
    for(i=1;i<=n;++i)
        printf("%d ",frunze[i]);
    return 0;
}