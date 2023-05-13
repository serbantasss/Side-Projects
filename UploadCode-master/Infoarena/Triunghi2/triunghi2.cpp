#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct point
{
    long long x,y;
};
struct triang
{
    point a,b,c;
    long long area;
}v[105];
inline long long makearea(point a,point b,point c)
{
    return abs((c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y));
}
inline bool inside(point a,point b,point c,point x)
{
    return makearea(a,b,c)==makearea(x,b,c)+makearea(a,x,c)+makearea(a,b,x);
}
inline bool cmp(triang x,triang y)
{
    return x.area<y.area;
}
int main()
{
	freopen("triunghi2.in","r",stdin);
	freopen("triunghi2.out","w",stdout);
	int n,i,ma=0,ind=0;
	point fant;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&v[i].a.x,&v[i].a.y,&v[i].b.x,&v[i].b.y,&v[i].c.x,&v[i].c.y);
        v[i].area=makearea(v[i].a,v[i].b,v[i].c);
        if(v[i].area>ma)
            ma=v[i].area,ind=i;
    }
    scanf("%lld%lld",&fant.x,&fant.y);
    vector<int>ans;
    for(i=1;i<=n;++i)
    {
        if(inside(v[i].a,v[i].b,v[i].c,fant))
            ans.push_back(i);
    }
    printf("%d ",ans.size());
    for(i=0;i<ans.size();++i)
    {
        printf("%d ",ans[i]);
    }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<n && ind;++i)
    {
        if(!inside(v[n].a,v[n].b,v[n].c,v[i].a))
            ind=0;
        if(!inside(v[n].a,v[n].b,v[n].c,v[i].b))
            ind=0;
        if(!inside(v[n].a,v[n].b,v[n].c,v[i].c))
            ind=0;
    }
    printf("\n%d",ind);
    return 0;
}