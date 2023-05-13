#include <bits/stdc++.h>
using namespace std;
long long mat[1005][1005],v[1005];
int main()
{
//    freopen("sediu.in","r",stdin);
//    freopen("sediu.out","w",stdout);
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&mat[i][j]);
    v[1]=sqrt(mat[1][3]*mat[1][2]/mat[2][3]);
    printf("%d ",v[1]);
    for(int i=2;i<=n;++i)
    {
        v[i]=mat[1][i]/v[1];
        printf("%lld ",v[i]);
    }
    return 0;
}