#include <cstdio>
using namespace std;
int v[100005];
int main()
{
    freopen("mutari.in","r",stdin);
    freopen("mutari.out","w",stdout);
    int n,i,j,ok=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d",&v[i]);
    for(i=2;i<=n && ok==0;++i)
        if(v[i]%v[1]!=0 || v[1]>v[i])
            ok=1;
    if(ok)
    {
        printf("-1");
        return 0;
    }
    long long ans=0;
    for(i=2;i<=n;++i)
        ans=ans+(long long)v[i]/v[1];
    printf("%lld\n",ans);
    for(i=2;i<=n;i++)
        for(j=1;j<=v[i]/v[1]-1;++j)
            printf("%d\n",i-1);
    for(i=n-1;i>=1;--i)
        printf("%d\n",i);
    return 0;

}