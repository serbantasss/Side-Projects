#include<bits/stdc++.h>
using namespace std;
int dp[505][10];
int main()
{
    //freopen("insule.out","r",stdin);
    //freopen("insule.in","w",stdout);
    int n,k,d,i,j;
    scanf("%d%d%d",&n,&k,&d);
    dp[0][0]=1;
    for(i=0;i<=n;++i)
        for(j=1;j<=k;++j)
        {
            if(j>=d)
                dp[i+j][1]=(dp[i+j][1]+dp[i][0])%1000000007;
            else
                dp[i+j][0]=(dp[i+j][0]+dp[i][0])%1000000007;
            dp[i+j][1]=(dp[i+j][1]+dp[i][1])%1000000007;
        }
    printf("%d",dp[n][1]);
    return 0;
    
}