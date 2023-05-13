#include <cstdio>
#include <algorithm>
using namespace std;
long long x, dp[100005];
int main()
{
    freopen("spargere2.in","r",stdin);
    freopen("spargere2.out","w",stdout);
    int n,i,j,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)
    {
        scanf("%lld",&x);
        if(i<=k)
            dp[i]=max(dp[i-1],x);
        else
            dp[i]=max(dp[i-1],x+dp[i-k]);
    }
    printf("%lld",dp[n]);
    return 0;
}