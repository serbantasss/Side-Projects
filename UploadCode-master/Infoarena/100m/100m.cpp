#include <bits/stdc++.h>
using namespace std;
long long v[5005];
int main()
{
    freopen("100m.in","r",stdin);
    freopen("100m.out","w",stdout);
    int n,i,j;
    long long ans=0;
    scanf("%d",&n);
    v[1]=1;
    for(i=2;i<=n;++i)
        for(j=i;j>=2;--j)
            v[j]=((1LL*j*v[j])%666013+(1LL*j*v[j-1])%666013)%666013;
    for(i=1;i<=n;++i)
        ans=(ans+v[i])%666013;
    printf("%lld",ans);
    return 0;
}