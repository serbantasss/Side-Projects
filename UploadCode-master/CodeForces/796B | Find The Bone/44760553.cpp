#include <cstdio>
using namespace std;
bool f[1000005];
int main()
{
    //freopen("1.in","r",stdin);
   // freopen("1.out","w",stdout);
    int n,m,k,a,i,j,b,poz,ok=0,pozfin;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;++i)
        {
            scanf("%d",&a);
            f[a]=1;
        }
    poz=1;
    for(i=1;i<=k;++i)
    {
        scanf("%d%d",&a,&b);
        if(f[poz] && !ok)
            ok=1,pozfin=poz;
        if(poz==a)
            poz=b;
        else
            if(poz==b)
                poz=a;
    }
    if(ok)
        printf("%d",pozfin);
    else
        printf("%d",poz);
    return 0;
}