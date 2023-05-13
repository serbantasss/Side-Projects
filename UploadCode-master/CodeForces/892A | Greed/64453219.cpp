#include <bits/stdc++.h>
using namespace std;
long long v[100005];
int main()
{
    //freopen("insule.in","r",stdin);
    //freopen("insule.out","w",stdout);
    int n,i,j;
    long long s=0,x;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%lld",&x);
        s+=x;
    }
    for(i=1;i<=n;++i)
        scanf("%lld",&v[i]);
    sort(v+1,v+n+1);
    if(s<=v[n]+v[n-1])
        printf("YES");
    else
        printf("NO");
    return 0;
}