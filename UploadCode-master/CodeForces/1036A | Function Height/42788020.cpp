#include <cstdio>
 
using namespace std;
 
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    if(b%a==0)
        printf("%lld",b/a);
    else
        printf("%lld",b/a+1);
    return 0;
}