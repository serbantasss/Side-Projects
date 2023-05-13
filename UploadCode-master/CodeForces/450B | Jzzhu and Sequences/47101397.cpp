#include <cstdio>
#include <string>
using namespace std;
long long modulo(long long a)
{
    if(a%1000000007<0)
        return 1000000007+a%1000000007;
    return a%1000000007;
}
int main()
{
    long long x,y,res,n;
    scanf("%lld%lld%lld",&x,&y,&n);
    if(n%6==1)
        printf("%lld",modulo(x));
    if(n%6==2)
        printf("%lld",modulo(y));
    if(n%6==3)
        printf("%lld",modulo(y-x));
    if(n%6==4)
        printf("%lld",modulo(-x));
    if(n%6==5)
        printf("%lld",modulo(-y));
    if(n%6==0)
        printf("%lld",modulo(x-y));
    return 0;
}