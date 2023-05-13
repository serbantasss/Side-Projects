#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define x first
#define id second
using namespace std;
pair<int,int> v[1000];
int main()
{
    freopen("borcane.in","r",stdin);
    freopen("borcane.out","w",stdout);
    int n,i;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&v[i].x);
        v[i].id=i;
    }
    sort(v+1,v+n+1);
    for(i=1; i<=n-2; ++i)
    {
        if(v[i].x==0)
            continue;
        for(int j=1; j<=v[i].x; ++j)
            printf("%d %d %d\n",v[i].id,v[i+1].id,v[n].id);
        v[n].x+=v[i].x*2;
        v[i+1].x-=v[i].x;
        v[i].x=0;
    }
    //for(i=1;i<=n;++i)
    //    printf("%d ",v[i].x);
    int k=v[n-1].x/3;
    for(int j=1; j<=k; ++j)
        printf("%d %d %d\n",v[n-1].id,v[n].id,v[n-2].id);
    for(int j=1; j<=2*k; ++j)
        printf("%d %d %d\n",v[n-2].id,v[n-1].id,v[n].id);
    if(v[n-1].x%3==1)
    {
        printf("%d %d %d\n",v[n-1].id,v[n].id,v[n-2].id);
        printf("%d %d %d\n",v[n-2].id,v[n].id,v[n-1].id);
        printf("%d %d %d\n",v[n-2].id,v[n].id,v[n-3].id);
        printf("%d %d %d\n",v[n-1].id,v[n-3].id,v[n].id);
        printf("%d %d %d\n",v[n-1].id,v[n-3].id,v[n].id);
    }
    if(v[n-1].x%3==2)
    {
        printf("%d %d %d\n",v[n-1].id,v[n].id,v[n-2].id);
        printf("%d %d %d\n",v[n-1].id,v[n].id,v[n-3].id);
        printf("%d %d %d\n",v[n-2].id,v[n-3].id,v[n].id);
        printf("%d %d %d\n",v[n-2].id,v[n-3].id,v[n].id);
    }
    return 0;

}