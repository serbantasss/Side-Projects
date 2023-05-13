#include <stdio.h>
int v[6000005],dp[6000005];
int main()
{
    freopen("ssm.in","r",stdin);
    freopen("ssm.out","w",stdout);
    int n,masum,mastart=1,maend=1,i,start=1;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d",&v[i]);
    dp[1]=masum=v[1];
    for(i=2;i<=n;++i) {
        if (dp[i - 1] >= 0)
            dp[i] = dp[i - 1] + v[i];
        else
            dp[i] = v[i],start=i;
        if(masum<dp[i])
            masum=dp[i],mastart=start,maend=i;
    }
    printf("%d %d %d\n",masum,mastart,maend);
    return 0;
}