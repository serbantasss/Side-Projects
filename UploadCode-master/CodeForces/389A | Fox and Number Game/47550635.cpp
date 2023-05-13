#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,a,b,c;
int main()
{
    scanf("%d%d",&n,&a);
    c=a;
    for(i=2;i<=n;++i)
        {
        scanf("%d",&b);
        c=__gcd(c,b);
        }
    printf("%d",c*n);
    return 0;
}