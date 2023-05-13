#include <bits/stdc++.h>
using namespace std;
long long diag1[1005][1005];
long long diag2[1005][1005];
#define max(a,b) (a<b)?b:a;
int main()
{
    freopen("diagonale.in","r",stdin);
    freopen("diagonale.out","w",stdout);
    int n,i,j,x;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            scanf("%d",&x);
            diag1[i][j]=diag1[i-1][j-1]+x;
            diag2[i][j]=diag2[i-1][j+1]+x;
        }
    long long ans=LLONG_MIN;
    for(i=1;i<=n;++i)
    {
        ans=max(ans,diag1[i][n]);
        ans=max(ans,diag2[i][1]);
        ans=max(ans,diag1[n][i]);
        ans=max(ans,diag2[n][i]);
    }
    printf("%lld",ans);
    return 0;
}