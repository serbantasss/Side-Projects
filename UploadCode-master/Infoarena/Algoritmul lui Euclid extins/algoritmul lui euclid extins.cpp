#include <cstdio>
using namespace std;
long long  n, a, b, c, d, x, y, xn, yn;
long long euclid(long long a, long long b, long long &x, long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long xn=0, yn=0, dn=0;
    dn=euclid(b, a%b, xn, yn);
    x=yn;
    y=xn-yn*(a/b);
    return dn;
}
int main()
{
    freopen("euclid3.in","r",stdin);
    freopen("euclid3.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        d=euclid(a, b, x, y);
        if(c%d!=0)
            printf("0 0\n");
        else
            printf("%lld %lld\n",x*(c/d),y*(c/d));
    }
    return 0;
}