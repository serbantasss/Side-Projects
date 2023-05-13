#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
    int x,y,c;
};
edge v[400001];
int t[100001],h[200001],c[200001];
int findset(int a)
{
    while(t[a]!=a)
        a=t[a];
    return a;
}
void unionset(int a,int b,int cost)
{
    if(h[a]==h[b])
    {
        t[b]=a;
        h[a]++;
        c[b]=cost;
    }
    else
        if(h[a]>h[b])
            t[b]=a,c[b]=cost;
        else
            t[a]=b,c[a]=cost;
}
int solve(int a,int b)
{
    int ans=0;
    while(a!=b)
    {
        if(h[a]<h[b])
        {
            ans=max(ans,c[a]);
            a=t[a];
        }
        else
        {
            ans=max(ans,c[b]);
            b=t[b];
        }
    }
    return ans;
}
bool cmp(edge a,edge b)
{
    return a.c<b.c;
}
int main()
{
    freopen("radiatie.in","r",stdin);
    freopen("radiatie.out","w",stdout);
    int n,m,i,k,x,y,c;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i)
        t[i]=i;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&c);
        v[i].x=x;
        v[i].y=y;
        v[i].c=c;
    }
    sort(v+1,v+m+1,cmp);
    int nr=0,cost=0;
    for(i=1;i<=m;++i)
    {
        int rx,ry;
        rx=findset(v[i].x);
        ry=findset(v[i].y);
        if(ry!=rx)
            unionset(rx,ry,v[i].c);
    }
    for(i=1;i<=k;++i)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",solve(x,y));
    }
    return 0;
}