#include <cstdio>
#include <algorithm>
using namespace std;
int f[200005],v[1005];
int main()
{
   // freopen("spargere2.in","r",stdin);
   // freopen("spargere2.out","w",stdout);
    int n,m,i,j,k,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d",&v[i]);
    for(i=1;i<=n;++i)
        for(j=i+1;j<=n;++j)
            f[v[i]+v[j]]++;
    for(i=1;i<=200000;++i)
        if(f[i]>ans)
            ans=f[i];
    printf("%d",ans);
    return 0;
}