#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
bool prim(int n)
{
    int rad=(int)sqrt((double)n);
    for(int i=2;i<=rad;i++)
            if(n%i==0)
                return 0;
    return 1;
}
int main()
{
    int t,i,n,j,rad;
    long long u,v,a1,a2,cmmdc;
    scanf("%d",&t);
    for(;t;--t)
    {
        scanf("%d",&n);
        u=v=n;
        while(!prim(v)) v--;
        u++;
        while(!prim(u)) u++;
        a1=2*(n+1)-2*(u+v)+u*v;
        a2=2*u*v;
        cmmdc=__gcd(a1,a2);
        printf("%lld/%lld\n",a1/cmmdc,a2/cmmdc);
    }
    return 0;
}
 