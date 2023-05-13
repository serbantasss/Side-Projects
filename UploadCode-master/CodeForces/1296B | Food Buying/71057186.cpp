#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    //freopen("disconnect.in","r",stdin);
    //freopen("disconnect.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long s=0,x;
        scanf("%lld",&x);
        while(1)
        {
            if(x<10)
            {
                s+=x;
                break;
            }
            s+=(x/10)*10;
            x=x%10+x/10;
        }
        printf("%lld\n",s);
    }
    return 0;
}