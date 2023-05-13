#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int nmax=100005;
int poz[nmax],h[nmax],euler[2*nmax],rmq[2*nmax][19],lg[2*nmax];
bool viz[nmax];
vector<int> adc[nmax];
int n,m,q;
void dfs(int nod,int adan)
{
    viz[nod]=1;
    h[nod]=adan;
    poz[nod]=m+1;
    euler[++m]=nod;
    for(int i=0;i<adc[nod].size();++i)
        if(!viz[adc[nod][i]])
        {
            dfs(adc[nod][i],adan+1);
            euler[++m]=nod;
        }
}
int main()
{
    freopen("lca.in","r",stdin);
    freopen("lca.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        adc[i].push_back(x);
        adc[x].push_back(i);
    }
    dfs(1,0);
    //rmq
    rmq[1][0]=1;
    for(int i=2;i<=m;++i)
        rmq[i][0]=euler[i],lg[i]=lg[i/2]+1;
    for(int j=1;(1<<j)<=m;++j)
        for(int i=1;i+(1<<j)-1<=m;++i)
            if(h[rmq[i][j-1]]<h[rmq[i+(1<<(j-1))][j-1]])
                rmq[i][j]=rmq[i][j-1];
            else
                rmq[i][j]=rmq[i+(1<<(j-1))][j-1];
    for(;q;--q)
    {
        int x,y,k;
        scanf("%d%d",&x,&y);
        if(poz[x]>poz[y])
            swap(x,y);
        x=poz[x];
        y=poz[y];
        k=lg[y-x+1];
        if(h[rmq[x][k]]<h[rmq[y-(1<<k)+1][k]])
            printf("%d\n",rmq[x][k]);
        else
            printf("%d\n",rmq[y-(1<<k)+1][k]);
    }
    return 0;
}