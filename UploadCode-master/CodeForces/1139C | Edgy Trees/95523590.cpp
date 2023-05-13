#include <bits/stdc++.h>
#define x first
#define y second
#define mod 1000000007
using namespace std;
vector<int> v[100005];
vector<int> conx;
bool viz[100005];
void dfs(int nod,int comp)
{
    viz[nod]=1;
    conx[comp]++;
    for(int i=0;i<v[nod].size();++i)
        if(!viz[v[nod][i]])
            dfs(v[nod][i],comp);
}
int main()
{
    int n,nr=-1,k;
    long long rez=0;
    scanf("%d%d\n",&n,&k);
    for(int i=1;i<n;++i)
    {
        int x,y,p;
        scanf("%d%d%d",&x,&y,&p);
        if(!p)
            v[x].push_back(y),v[y].push_back(x);
    }
    for(int i=1;i<=n;++i)
        if(!viz[i])
        {
            conx.push_back(0);
            dfs(i,++nr);
        }
//    printf("%d",nr+1);
    rez=n;
    for(int i=2;i<=k;++i)
        rez=(rez*n+mod)%mod;
    for(int i=0;i<=nr;++i)
    {
        long long r=conx[i];
        for(int j=2;j<=k;++j)
            r=(r*(long long)conx[i]+mod)%mod;
        rez=(rez-r+mod)%mod;
    }
    printf("%lld",rez);
    return 0;
}