#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
int n,k,nr;
vector<int> v[100005];
bool psi[100005],viz[100005];
void dfs(int nod,int pisici)
{
    viz[nod]=1;
    if(psi[nod])
        pisici++;
    else
        pisici=0;
    if(pisici>k)
        return;
    if(v[nod].size()==1 && nod!=1)
        nr++;
    for(int i=0;i<v[nod].size();++i)
    if(!viz[v[nod][i]])
    {
        dfs(v[nod][i],pisici);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
    scanf("%d",&psi[i]);
    for(int i=1;i<n;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    printf("%d",nr);
    return 0;
}