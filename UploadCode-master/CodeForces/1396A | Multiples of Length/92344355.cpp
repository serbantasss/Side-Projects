#include <cstdio>
 
using namespace std;
long long v[100005];
int main()
{
    long long n,i;
    scanf("%lld",&n);
    for(i=1;i<=n;++i)
        scanf("%lld",&v[i]);
    if(n==1)
    {
        printf("1 1\n0\n1 1\n0\n1 1\n%lld",-v[1]);
        return 0;
    }
    if(n==2)
    {
        printf("1 1\n%lld\n2 2\n%lld\n1 1\n0\n",-v[1],-v[2]);
        return 0;
    }
    if(n==3)
    {
        printf("1 1\n%lld\n2 2\n%lld\n3 3\n%lld\n",-v[1],-v[2],-v[3]);
        return 0;
    }
    printf("2 %lld\n",n);
    for(i=2;i<=n;++i)
        printf("%lld ",(v[i]%n)*(n-1));
    printf("\n1 1\n%lld\n1 %lld\n0 ",-v[1],n);
    for(i=2;i<=n;++i)
        printf("%lld ",-(v[i]+(v[i]%n)*(n-1)));
    return 0;
}