#include <cstdio>

using namespace std;
struct intt
{
    long long  a,b;
};
intt v[200005];
long long n,k;
bool ok(long long sum)
{
    long long  i;
    long long s=0;
    for(i=1; i<=n; ++i)
    {
        if(sum>=v[i].a)
            s+=(sum-v[i].a)/v[i].b+1;
        if(s>=k)
            return 1;
    }
    return 0;
}
int main()
{
    freopen("tarabe.in","r",stdin);
    freopen("tarabe.out","w",stdout);
    long long i,j,a,b;
    long long st=1,dr=0,mid,sol=0;
    scanf("%lld%lld",&n,&k);
    for(i=1; i<=n; ++i)
    {
        scanf("%lld%lld",&b,&a);
        v[i].a=a;
        v[i].b=b;
        if(a*k+b*(k-1)>dr)
            dr=a*k+b*(k-1);
    }
    while(st<=dr)
    {
        mid=(st+dr)/2;
        if(ok(mid))
            dr=mid-1;
        else
            st=mid+1;
    }
    for(i=1;i<=n;++i)
    {
        if(st<v[i].a)
            continue;
        mid=(st-v[i].a)/v[i].b+1;
        sol+=mid*v[i].a+mid*(mid-1)*v[i].b/2;
        k=k-mid;
    }
    sol+=k*st;
    printf("%lld",sol);
    return 0;
}