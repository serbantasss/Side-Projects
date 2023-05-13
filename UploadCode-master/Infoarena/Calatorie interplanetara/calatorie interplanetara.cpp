#include <bits/stdc++.h>
using namespace std;
long long v1[55],v2[55],mi=1000000000000000,dp[100][5000];
int main()
{
    freopen("calatorie.in","r",stdin);
    freopen("calatorie.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long i,n,j;
        long long smax=0;
        scanf("%lld",&n);
        for(i=1;i<=n-1;++i)
        {
            scanf("%lld%lld",&v1[i],&v2[i]);
            smax=smax+v2[i];
        }
        mi=1000000000000000;
        for(i=1;i<=n-1;++i)
        {
            dp[i][0]=dp[i-1][0]+v1[i];
            for(j=1;j<=smax;++j)
                dp[i][j]=mi;
        }
        for(i=1;i<=n-1;++i)
            for(j=0;j<=smax;++j)
                if(j>=v2[i] && dp[i-1][j]+v1[i]>dp[i-1][j-v2[i]])
                    dp[i][j]=dp[i-1][j-v2[i]];
                else
                    dp[i][j]=dp[i-1][j]+v1[i];
        for(j=0;j<=smax;++j)
            if(mi>dp[n-1][j]+j*j*j*j)
                mi=dp[n-1][j]+j*j*j*j;
        printf("Consumul minim = %lld.\n",mi);
    }
    return 0;
}