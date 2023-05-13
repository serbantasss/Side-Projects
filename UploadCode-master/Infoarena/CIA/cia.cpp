#include <cstdio>
#include <algorithm>
using namespace std;
long long int a[70005],b[70005],v[10000005],st[10000005],dr[10000005];
int main()
{
    freopen("cia.in","r",stdin);
    freopen("cia.out","w",stdout);
    int n,t,k,m,i;
    long long ans=0;
    scanf("%d%d%d%d",&n,&t,&k,&m);
    for(i=0; i<t; ++i)
        scanf("%lld",&a[i]);
    for(i=0; i<t; ++i)
        scanf("%lld",&b[i]);
    for(i=0; i<n; ++i)
    {
        v[i]=a[i%t]^b[i/t];
        if(i%k==0)
            st[i]=v[i];
        else
            st[i]=1LL*st[i-1]*v[i]%m;
    }
    for(i=n-1;i>=0;--i)
        if((i+1)%k==0)
            dr[i]=v[i];
        else
            dr[i]=1LL*dr[i+1]*v[i]%m;
    for(i=0;i<=n-k;++i)
        if(i%k==0)
            ans=ans^(st[i+k-1]);
        else
            ans=ans^(1LL*st[i+k-1]*dr[i]%m)%m;
    printf("%lld",ans);
    return 0;
}