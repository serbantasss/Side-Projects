#include <bits/stdc++.h>
using namespace std;
int v[200005],dp[200005][2];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,ok=1,x;//ok=0 friend ok=1 you
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&v[i]);
        for(int i=1;i<=n+2;++i)
            dp[i][0]=dp[i][1]=INT_MAX-200005;
        dp[1][0]=v[1];
        dp[2][0]=v[1]+v[2];
        for(int i=1;i<n;++i)
        {
            dp[i+1][0]=min(dp[i+1][0],dp[i][1]+v[i+1]);
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]);
            dp[i+2][0]=min(dp[i+2][0],dp[i][1]+v[i+1]+v[i+2]);
            dp[i+2][1]=min(dp[i+2][1],dp[i][0]);
        }
        printf("%d\n",min(dp[n][0],dp[n][1]));
    }
    return 0;
}