#include <cstdio>
using namespace std;
int main()
{
    freopen("prodiv.in","r",stdin);
    freopen("prodiv.out","w",stdout);
    long long int n,cn,a=1,b=1,i,d,nrval=0,lol=1;
    scanf("%lld",&n);
    cn=n;
    for(i=2; i*i<=cn; ++i)
        if(cn%i==0)
        {
            int nr=0;
            while(cn%(i*i)==0)
                cn/=(i*i),a*=i;
            if(cn%i==0)
                lol*=2,b*=i,cn/=i;
        }
    if(cn!=1)
        lol*=2,b*=cn;
    printf("%lld %lld\n%lld",a*b,a,lol);
    return 0;
}