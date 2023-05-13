#include <cstdio>
 
using namespace std;
bool mat[1005][1005];
int r[1005],c[1005];
int main()
{
    int n,m,i,j;
    long long ans=1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&r[i]);
        for( j=1;j<=r[i];++j)
            mat[i][j]=1;
    }
    for(i=1;i<=m;++i)
    {
        scanf("%d",&c[i]);
        for(j=1;j<=c[i];++j)
            mat[j][i]=1;
    }
    bool ok=1;
    for(i=1;i<=n && ok;++i)
        if(mat[i][r[i]+1])
            ok=0;
    for(i=1;i<=m && ok;++i)
        if(mat[c[i]+1][i])
            ok=0;
    if(ok==0)
    {
        printf("0");
        return 0;
    }
    for(i=1;i<=n;++i)
        mat[i][r[i]+1]=1;
    for(i=1;i<=m;++i)
        mat[c[i]+1][i]=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(!mat[i][j])
                ans=(ans*2)%1000000007;
    printf("%lld",ans);
    return 0;
}