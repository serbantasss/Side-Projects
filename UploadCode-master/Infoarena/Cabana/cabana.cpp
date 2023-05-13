#include <bits/stdc++.h>
using namespace std;
long long fact[1000005],mod=1000000007;
long long lgput(long long n,long long p)
{
    long long a=n;
    long long sol=1;
    for (long long i=0ll;(1ll<<i)<=p;i++)
    {
        if ((1ll<<i)&p)
            sol=(sol*a)%mod;
        a=(a*a)%mod;
    }
    return (sol%mod);
}
 
int main()
{
    freopen("cabana.in","r",stdin);
    freopen("cabana.out","w",stdout);
    int t;
    fact[1]=1;
    for(long long i=2;i<=1000000;++i)
        fact[i]=(fact[i-1]*i)%mod;
    scanf("%d",&t);
    while(t--)
    {
        long long n,k;
        scanf("%lld%lld",&n,&k);
        printf("%lld\n",(lgput(fact[k],n/k+1)*lgput(fact[k-n%k],1000000005))%mod);
    }
    return 0;
}