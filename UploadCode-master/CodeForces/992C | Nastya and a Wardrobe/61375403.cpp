#include <cstdio>
using namespace std;
 
    int mod=1000000007;
long long pute(long long x,long long y)
{
    if(y==0)
        return 1;
    long long int r=pute(x,y/2);
    if(y%2==0)
        return (r*r)%mod;
    else
        return (r*r*x)%mod;
}
int main()
{
    long long x,k;
    scanf("%lld%lld",&x,&k);
    if(x==0)
        printf("0");
    else
        if(k==0)
    {
        x=x*2;
        printf("%lld",x%mod);
    }
    else
    {
        x=(2*x-1)%mod;
        printf("%lld",(2*x*pute(2,k-1)+1)%mod);
    }
    return 0;
}