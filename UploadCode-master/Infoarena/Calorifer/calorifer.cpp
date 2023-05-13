#include <bits/stdc++.h>
using namespace std;
struct intt
{
    int p3,p2,c;
} v[100005];
bool cmp(intt a,intt b)
{
    if(a.p2==b.p2)
        return a.p3<b.p3;
    return a.p2>b.p2;
}
int main()
{
    freopen("calorifer.in","r",stdin);
    freopen("calorifer.out","w",stdout);
    int n,m,i,j,k,l,cm,x;
    scanf("%d",&n);
    scanf("%d",&v[1].c);
    cm=v[1].c;
    for(i=2; i<=n; ++i)
    {
        scanf("%d",&v[i].c);
        cm=__gcd(cm,v[i].c);
    }
    for(i=1; i<=n; ++i)
    {
        x=v[i].c/cm;
        while(x%2==0)
            x/=2,v[i].p2++;
        while(x%3==0)
            x/=3,v[i].p3++;
        if(x>1)
            {
            printf("-1");
            return 0;
        }
    }
    sort(v+1,v+n+1,cmp);
    for(i=1; i<n; ++i)
    {

        if (v[i].p2<v[i+1].p2 || v[i].p3>v[i+1].p3)
        {
            printf("-1");
            return 0;
        }
    }
    for(i=1; i<=n; ++i)
        printf("%d ",v[i].c);
    return 0;
}