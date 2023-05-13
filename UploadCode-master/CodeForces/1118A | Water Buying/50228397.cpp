#include <cstdio>
using namespace std;
int main()
{
   // freopen("cmmmc.in","r",stdin);
   // freopen("cmmmc.out","w",stdout);
    long long int n,i,m,a,b;
    scanf("%lld",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%lld%lld%lld",&m,&a,&b);
        if(m%2==0)
        {
            if(2*a<b)
                printf("%lld\n",m*a);
            else
                printf("%lld\n",m/2*b);
        }
        else
        {
            if(2*a<b)
                printf("%lld\n",m*a);
            else
                printf("%lld\n",(m-1)/2*b+a);
        }
    }
    return 0;
}