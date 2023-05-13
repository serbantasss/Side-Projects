#include <cstdio>
#include <string>
using namespace std;
bool v[105][105];
int main()
{
    long long int n,a,b;
    scanf("%lld%lld",&a,&b);
    if(b-a+1<3)
        printf("-1");
    else
    {
        if(b-a+1>3 && a%2==1)
            printf("%lld %lld %lld",a+1,a+2,a+3);
        else
        {
            if(a%2==0)
                printf("%lld %lld %lld",a,a+1,a+2);
            else
                printf("-1");
        }
    }
    return 0;
}