#include <cstdio>
#include <algorithm>
using namespace std;
int poz[100005],f[100005];
int main()
{
    freopen("intersort.in","r",stdin);
    freopen("intersort.out","w",stdout);
    int n,i,j,x,nr=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        poz[x]=i;
        if(x==i && x!=1)
            nr--;
    }
    x=0;
    for(i=1;i<=n;++i)
        if(!f[i])
    {
        j=poz[i];
        if(j!=poz[j])
            x++;
        while(j!=i)
            f[j]=1,j=poz[j];
    }
    nr+=n+x-2;
    printf("%d",nr);
    return 0;
}