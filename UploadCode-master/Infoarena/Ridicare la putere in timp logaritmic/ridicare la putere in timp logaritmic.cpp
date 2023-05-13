#include <cstdio>
using namespace std;

int main()
{
    freopen("lgput.in","r",stdin);
    freopen("lgput.out","w",stdout);
    long long n,p,ans,mod=1999999973;
    scanf("%lld%lld",&n,&p);
    ans=1;
    for(long long i=0;(1<<i)<=p;++i)
    {
        if((1<<i)&p)
            ans=(ans*n)%mod;
        n=(n*n)%mod;
    }
    printf("%lld",ans);
    return 0;
}