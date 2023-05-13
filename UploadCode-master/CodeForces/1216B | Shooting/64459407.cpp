#include <bits/stdc++.h>
using namespace std;
struct cojoegay
{
    long long x,ind;
};
cojoegay v[1005];
bool mycmp(cojoegay a,cojoegay b)
{
    return a.x<b.x;
}
int main()
{
    //freopen("insule.in","r",stdin);
    //freopen("insule.out","w",stdout);
    long long n,i,x=0,sum=0;
    scanf("%lld",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%lld",&v[i].x);
        v[i].ind=i;
    }
    sort(v+1,v+n+1,mycmp);
    for(i=n;i>=1;--i)
    {
        sum=(v[i].x*x+1)+sum;
        x++;
    }
    printf("%lld\n",sum);
    for(i=n;i>=1;--i)
    {
        printf("%lld ",v[i].ind);
    }
    return 0;
}