#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#define x first
#define y second
using namespace std;
const int nmax=200005;//2x10ˆ5 + 5
pair<int,int> f[nmax],qu[nmax];
int v[nmax];
long long sp[nmax];
int main()
{
    int n,q;
    long long ans=0;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",&v[i]);
    for(int i=1;i<=q;++i)
    {
        int s,d;
        scanf("%d %d",&s,&d);
        qu[i].x=s,qu[i].y=d;
        f[s].x++;
        f[d+1].x--;
    }
    for(int i=1;i<=n;++i)
        f[i].x+=f[i-1].x,f[i].y=i;
    sort(v+1,v+n+1);
    sort(f+1,f+n+1);
    for(int i=1;i<=n;++i)
        sp[f[i].y]=v[i];
    for(int i=1;i<=n;++i)
        sp[i]+=sp[i-1];
    for(int i=1;i<=q;++i)
        ans+=sp[qu[i].y]-sp[qu[i].x-1];
    printf("%lld",ans);
    return 0;
}