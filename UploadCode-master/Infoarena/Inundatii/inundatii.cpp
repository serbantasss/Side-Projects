//cojoegay
#include<bits/stdc++.h>
using namespace std;
int v[50005][3],n;
long long solve(int ind)
{
    long long ret=0;
    for(int i=1;i<=n;++i)
        v[i][ind]-=i;
    for(int i=1;i<=n;++i)
        ret+=abs(v[i][ind]-v[(n+1)/2][ind]);
    return ret;
}
int main()
{
    freopen("inundatii.in","r",stdin);
    freopen("inundatii.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d%d",&v[i][0],&v[i][1],&v[i][2]);
    printf("%lld",solve(0)+solve(1)+solve(2));
    return 0;
}