#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005],ans[1005];
int main()
{
    freopen("stiva2.in","r",stdin);
    freopen("stiva2.out","w",stdout);
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    if(n%2==1)
    {
        printf("0");
        return 0;
    }
    dp[1][1]=2;
    for(i=2;i<=n;i++)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=dp[i-1][2];
        for(j=2;j<=i;++j)
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%9973;
    }
    ans[0]=1;
    for(i=2;i<=n;i+=2)
        if(i-k-1<0)
            for(j=0;j<i;++j)
                ans[i]=(ans[i]+ans[j]*dp[i-j][0])%9973;
        else
            for(j=i-k-1;j<i;++j)
                ans[i]=(ans[i]+ans[j]*dp[i-j][0])%9973;
    printf("%d\n",ans[n]);
    return 0;
}