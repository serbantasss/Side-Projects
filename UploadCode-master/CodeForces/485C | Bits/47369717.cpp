#include <cstdio>
#define ll long long
using namespace std;
ll f(ll a,ll b)
{
    ll x=1;
    while(x*2<=b)
        x*=2;
    if(a==b)
        return a;
    if(x<=a)
        return f(a-x,b-x)+x;
    if(x*2-1<=b)
        return x*2-1;
    return x-1;
}
int main()
{
    int n,i,j,k,x1,x2;
    scanf("%d",&n);
    for(;n;--n)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",f(x,y));
    }
    return 0;
}