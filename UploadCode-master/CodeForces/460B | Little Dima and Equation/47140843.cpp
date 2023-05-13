#include <cstdio>
#include <vector>
#define ll long long
using namespace std;
vector<ll> v;
ll pow(ll base,ll power)
{
    ll x=1;
    for(int i=1;i<=power;++i)
        x=x*base;
    return x;
}
ll digisum(ll num)
{
    ll sum=0;
    do
    {
        sum=sum+num%10;
        num/=10;
    }while(num);
    return sum;
}
int main()
{
    ll possum,posnum,a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    for(possum=1;possum<=81;possum++)
    {
        posnum=b*pow(possum,a)+c;
        if(posnum>1000000000)
            break;
        if(digisum(posnum)==possum)
        {
            v.push_back(posnum);
        }
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();++i)
        printf("%d ",v[i]);
    return 0;
}