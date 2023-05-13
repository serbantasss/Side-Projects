#include <cstdio>

using namespace std;
long long int sumap[3005][3005],smax[100005];
short int cif[3005][3005];
int main()
{
    freopen("tablou.in","r",stdin);
    freopen("tablou.out","w",stdout);
    int k,i,j;
    long long int n,m,s=0,s1=0;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%1d",&cif[i][j]);
            s+=cif[i][j];
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            sumap[i][j]=sumap[i-1][j]+sumap[i][j-1]-sumap[i-1][j-1]+cif[i][j];
    scanf("%d",&k);
    for(i=1;i<=k;++i)
        smax[i]=s;
    for(i=1;i<=k;i++)
    {
        int x,y,x1,y1,c;
        scanf("%d%d%d%d%d",&x,&y,&x1,&y1,&c);
        smax[i]+=(c*((long long)y1-y+1)*((long long)x1-x+1)-sumap[x1][y1]+sumap[x1][y-1]+sumap[x-1][y1]-sumap[x-1][y-1]);
        s1+=smax[i];
    }
    for(i=1;i<=k;i++)
        printf("%lld\n",smax[i]*n*m*(k-1)-(s1-smax[i])*n*m);
    return 0;
}