#include <cstdio>
using namespace std;
const int nmax=1024;
int val[nmax+5][nmax+5],alt[nmax+5][nmax+5],dir[nmax+5][nmax+5];
int n;
int x[]={0,0,-1,1},y[]={1,-1,0,0};
int construct(int i,int j)
{
    if(alt[i][j]>0)
        return alt[i][j];
    int m=0,l=0;
    for(int k=0;k<4;++k)
        if(i+x[k]>0 && i+x[k]<=n && j+y[k]>0 && j+y[k]<=n)
            if(val[i+x[k]][j+y[k]]<val[i][j])
            {
            l=construct(i+x[k],j+y[k]);
            if(l>m)
            {
                m=l;
                dir[i][j]=k;
            }
            }
    alt[i][j]=m+1;
    return alt[i][j];
}
void drum(int i,int j)
{
    if(alt[i][j]!=1)
        drum(i+x[dir[i][j]],j+y[dir[i][j]]);
    printf("%d %d\n",i,j);
}
int main()
{
    freopen("alpin.in","r",stdin);
    freopen("alpin.out","w",stdout);
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            scanf("%d",&val[i][j]);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            construct(i,j);
    int m=0,mi,mj;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            if(alt[i][j]>m)
            {
                m=alt[i][j];
                mi=i;
                mj=j;
            }
        }
    printf("%d\n",m);
    drum(mi,mj);
    return 0;
}