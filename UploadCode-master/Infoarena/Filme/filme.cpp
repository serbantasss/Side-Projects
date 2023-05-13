#include <cstdio>
#include <algorithm>
using namespace std;
int p[10005],q[10005];
int main()
{
    freopen("filme.in","r",stdin);
    freopen("filme.out","w",stdout);
    int n,m,i,ans=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&p[i],&q[i]);
        p[i]+=q[i];
    }
    sort(p+1,p+n+1);
    for(i=1;i<=n;++i)
        if(p[i]<=m)
    {
        ans++;
        m-=p[i];
    }
    else
        break;
    printf("%d",ans);
    return 0;
}