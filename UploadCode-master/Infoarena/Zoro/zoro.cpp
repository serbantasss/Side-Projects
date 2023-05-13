#include <cstdio>
#include <algorithm>

using namespace std;
int l[1000005],c[1000005],dl[1000005],dc[1000005];
int main()
{
    freopen("zoro.in","r",stdin);
    freopen("zoro.out","w",stdout);
    int n,m,p,i,j,s,f;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
    {
        scanf("%d",&p);
        l[p]=i;
        c[p]=j;
        if(i==1&&j==1) s=p;
        if(i==n&&j==m) f=p;
    }
    dl[1]=dc[1]=1;
    for(i=s-1;i>=f;i--)
    {
        p=max(dl[l[i]],dc[c[i]]);
        if(p>0)
            p++;
        dl[l[i]]=p;
        dc[c[i]]=p;
    }
    printf("%d",dl[l[f]]);
    return 0;
}