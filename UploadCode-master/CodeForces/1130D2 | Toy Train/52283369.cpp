#include <cstdio>
#include <algorithm>
using namespace std;
int f[5005];
long long v[5005];
int main()
{
    //freopen("compact.in","r",stdin);
   // freopen("compact.out","w",stdout);
    int n,m,i,j,a,b;
    long long x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&a,&b);
        if(!f[a])
            f[a]=b;
        else
            if((f[a]-a+n)%n>(b-a+n)%n)
                f[a]=b;
        v[a]++;
    }
    for(i=1;i<=n;++i)
    {
        x=0;
        for(j=1;j<=n;++j)
            if(f[j])
                {
               long long   s=(j+n-i)%n+(v[j]-1)*(n)+(f[j]-j+n)%n;
                if(s>x)
                    x=s;}
        printf("%lld ",x);
    }
    return 0;
}