#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;
ll v[100005];
ll genereaza(ll x)
{
    ll s=0,cx=x;
    do
    {
        s+=x%10;
        x/=10;
    }while(x);
    return cx+s;
}
vector<ll> vv;
int main()
{
    freopen("crescator3.in","r",stdin);
    freopen("crescator3.out","w",stdout);
    int n,i,j,nr=0;
    ll elem;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%lld",&v[i]);
    elem=v[1];
    while(elem<v[n])
        {
            vv.push_back(elem);
            elem=genereaza(elem);
        }
    for(i=1;i<=n;++i)
        if(binary_search(vv.begin(),vv.end(),v[i]))
            nr++;
    printf("%d",nr);
    return 0;
}