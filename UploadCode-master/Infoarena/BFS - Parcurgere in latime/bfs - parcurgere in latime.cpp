#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int NMAX=100000;
vector<int>G[NMAX+5];
queue<int>q;
bool viz[NMAX+5];
int d[NMAX+5],pred[NMAX+5];
void bfs(int u)
{
    int v;
    q.push(u);
    viz[u]=1;
    while(!q.empty())
    {
        u=q.front();
        for(int i=0;i<G[u].size();++i)
        {
            v=G[u][i];
            if(!viz[v])
            {
                viz[v]=1;
                d[v]=d[u]+1;
                pred[v]=u;
                q.push(v);
            }
        }
        q.pop();
    }
}
int main()
{
    freopen("bfs.in","r",stdin);
    freopen("bfs.out","w",stdout);
    int n,m,i,u,v,x;
    scanf("%d%d%d",&n,&m,&x);
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        //G[v].push_back(u);
    }
    bfs(x);
    for(i=1;i<=n;++i)
        if(d[i]>0 || i==x)
            printf("%d ",d[i]);
        else
            printf("-1 ");
    return 0;
}