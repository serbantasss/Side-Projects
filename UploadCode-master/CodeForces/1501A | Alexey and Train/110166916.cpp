#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int a[105],b[105],t[105];
int main()
{
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        long long ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d%d",&a[i],&b[i]);
        for(int i=1;i<=n;++i)
            scanf("%d",&t[i]);
        for(int i=1;i<=n;++i)
        {
            ans+=a[i]-b[i-1]+t[i];
            if(i==n)
                break;
            ans+=(b[i]-a[i]+1)/2;
            if(ans<b[i])
                ans=b[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}