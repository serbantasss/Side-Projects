#include <cstdio>
using namespace std;
long long int calc(long long int x,long long int a,long long int b)
{
    return (long long int)(((double)a*x)/(double)b);
}
int main()
{
    long long int n,i,j,m,x,a,b;
    scanf("%lld%lld%lld",&n,&a,&b);
    for(;n;--n)
    {
        scanf("%lld",&x);
        long long int st=1,dr=x,mid,ans;
        long long int  smax=calc(x,a,b),c;
        while(st<=dr)
        {
            mid=(st+dr)/2;
            if(calc(mid,a,b)==smax)
            {
                dr=mid-1;
                ans=mid;
            }
            else
                st=mid+1;
        }
        if(smax==0)
            printf("%lld ",x);
        else
            printf("%lld ",x-ans);
    }
    return 0;
}