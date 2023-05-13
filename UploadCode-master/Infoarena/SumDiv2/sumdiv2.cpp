#include <bits/stdc++.h>
using namespace std;
long long p[1000005],q[1000005];
pair<int,int> v[100005];
int main()
{
    freopen("sumdiv2.in","r",stdin);
    freopen("sumdiv2.out","w",stdout);
    int n,i,j,d,bmax=0,a,b;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%d %d",&a,&b);
        v[i].first=a;
        v[i].second=b;
        if(b>bmax)
            bmax=b;
    }
    for(i=2; i<=bmax; i++)
    {
        for(j=i; j<=bmax; j+=i)
            p[j]+=i;
        p[i]++;
        q[i]=q[i-1]+p[i];
    }
    for(i=1;i<=n;++i)
    {
        printf("%lld\n",q[v[i].second]-q[v[i].first-1]);
    }
    return 0;
}