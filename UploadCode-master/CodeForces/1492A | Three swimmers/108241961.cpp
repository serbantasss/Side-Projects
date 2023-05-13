#include <cstdio>
#include <algorithm>
#define x first
#define y second
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int p,a,b,c;
        scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
        if(p%a==0 || p%b==0 || p%c==0)
            printf("0\n");
        else
        {
            a=a-p%a;
            b=b-p%b;
            c=c-p%c;
            printf("%lld\n",min(a,min(b,c)));
        }
    }
    return 0;
}