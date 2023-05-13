#include <cstdio>
#include <algorithm>
#define ll long long int
using namespace std;
ll findsum(ll n)
{
    if(n%2==1)
        return -(n/2+1);
    return n/2;
}
int main()
{
    //freopen("1.in","rt",stdin);
    //freopen("1.out","wt",stdout);
    int q;
    ll n,l,r;
    scanf("%d",&q);
    for(;q;--q)
    {
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",findsum(r)-findsum(l-1));
    }
    return 0;
}