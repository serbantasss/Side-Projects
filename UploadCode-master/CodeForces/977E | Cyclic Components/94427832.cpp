#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[200005];
bool viz[200005];
int nr;
void dfs(int nod,int start)
{
    viz[nod]=1;
    if(v[nod].size()!=2)
        return;
    if(nod==start)
    {
        nr++;
        return;
    }
    if(!viz[v[nod][0]])
        dfs(v[nod][0],start);
    if(!viz[v[nod][1]])
        dfs(v[nod][1],start);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;++i)
        if(v[i].size()==2 && !viz[i])
        {
            viz[i]=1;
            dfs(v[i][0],v[i][1]);
        }
    printf("%d",nr);
    return 0;
}