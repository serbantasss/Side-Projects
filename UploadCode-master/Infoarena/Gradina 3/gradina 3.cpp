#include <cstdio>
using namespace std;
int sum[1005][1005];
bool mat[1005][1005];
int main()
{
    freopen("gradina3.in","r",stdin);
    freopen("gradina3.out","w",stdout);
    int n,p,k,i,j,x,y,c;
    scanf("%d%d%d",&n,&p,&k);
    for(i=1;i<=p;++i)
    {
        scanf("%d%d",&x,&y);
        mat[x][y]=1;
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+mat[i][j];
    int mac=0,cnt=0;
    for(i=1;i<=n-k+1;++i)
        for(j=1;j<=n-k+1;++j)
        {
            x=i+k-1;
            y=j+k-1;
            c=sum[x][y]+sum[i-1][j-1]-sum[i-1][y]-sum[x][j-1];
            if(c>mac)
                mac=c,cnt=1;
            else if (c==mac)
                cnt++;
        }
    printf("%d\n%d",mac,cnt);
    return 0;
}