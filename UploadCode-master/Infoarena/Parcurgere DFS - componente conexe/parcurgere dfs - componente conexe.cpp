#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#define x first
#define y second
#define intmax 2000000000
using namespace std;
bool viz[100005];
vector<int> adc[100005];
void dfs(int nod)
{
    viz[nod]=1;
    for(int i=0;i<adc[nod].size();++i)
        if(!viz[adc[nod][i]])
            dfs(adc[nod][i]);
}
int main()
{
    freopen("dfs.in","r",stdin);
    freopen("dfs.out","w",stdout);
    int n,m,a,b,nr=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&a,&b);
        adc[a].push_back(b);
        adc[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
        if(!viz[i])
            dfs(i),nr++;
    printf("%d",nr);
    return 0;
}