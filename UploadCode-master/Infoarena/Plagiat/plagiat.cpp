#include<cstdio>
#include<algorithm>
using namespace std;
int x[409],y[409];
struct point
{
    int x,y;
}a[160009];
bool cmp(point a,point b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}
int main()
{
    freopen("plagiat.in","r",stdin);
    freopen("plagiat.out","w",stdout);
    int t,i,j,nr,n;
    scanf("%d",&t);
    for(;t;--t)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x[i]);
            scanf("%d",&y[i]);
        }
        nr=0;
        for(i=1;i<=n;i++)
            for(j=1; j<=n; j++)
                if(i!=j)
                {
                    nr++;
                    a[nr].x=x[i]-x[j];
                    a[nr].y=y[i]-y[j];
                }
        sort(a+1,a+nr+1,cmp);
        for(i=3;i<=nr;i++)
            if(a[i].x==a[i-1].x&&a[i-1].x==a[i-2].x&&a[i].y==a[i-1].y&&a[i-1].y==a[i-2].y)
                break;
        if(i<=nr)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}