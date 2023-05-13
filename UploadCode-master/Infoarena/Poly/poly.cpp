#include <bits/stdc++.h>
using namespace std;
int dp[200],bitmask[30005];
int v[]= {2,3,7,11,19,23,37};
int main()
{
    freopen("poly.in","r",stdin);
    freopen("poly.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
    {
        int x;
        scanf("%d",&x);
        for(int k=0; k<7; ++k)
            if(x%v[k]==0)
                bitmask[i]=(bitmask[i]|(1<<k));
    }
    dp[bitmask[1]]=1;
    for(int i=2; i<=n; ++i)
    {
        for(int mask=0; mask<(1<<7); ++mask)
            if(!(mask&bitmask[i]) && dp[bitmask[i]]<=dp[mask])
                dp[bitmask[i]]=dp[mask]+1;
    }
    int ans=0;
    for(int mask=0; mask<(1<<7); ++mask)
        if(dp[mask]>ans)
            ans=dp[mask];
    printf("%d",ans);
    return 0;
}