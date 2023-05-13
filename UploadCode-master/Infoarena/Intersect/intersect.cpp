#include <cstdio>
using namespace std;
const int nmax=150;
int dp[nmax+5][nmax*nmax+5];
int main()
{
    freopen("intersect.in","r",stdin);
    freopen("intersect.out","w",stdout);
    int t,n,m,i,j,k;
    scanf("%d",&t);
    dp[0][0]=1;
    for(i=0;i<nmax;++i)
        for(j=0;j<=i*i;++j)
            if(dp[i][j])
                for(k=1;k<nmax && i+k<=nmax && j+i*k<=nmax*nmax;++k)
                    dp[i+k][j+i*k]=dp[i][j]+k*(i+1);
    for(;t;--t)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",dp[n][m]);
    }
    return 0;
}