#include <bits/stdc++.h>
using namespace std;
int dp[10005];
const int mod=9001;
int main()
{
    freopen("flori4.in","r",stdin);
    freopen("flori4.out","w",stdout);
    int n,i;
    scanf("%d",&n);
    dp[1]=1;
    dp[2]=2;
    for(i=3;i<=n;++i)
        dp[i]=((dp[i-1]+dp[i-2])%mod+1)%mod;
    printf("%d",dp[n]);
    return 0;
}