#include <bits/stdc++.h>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
        freopen("reflex.in","r",stdin);
        freopen("reflex.out","w",stdout);
    long long n,m,k;
    scanf("%lld%lld",&n,&m);
    n--;m--;
    k=cmmdc(n,m);
    printf("%lld ",n*m/k+1);
    n/=k;
    m/=k;
    if(n%2==0)
        printf("4\n");
    else if(m%2==0)
        printf("2\n");
        else
            printf("3\n");
    printf("%lld %lld",m-1,n-1);
    return 0;
}