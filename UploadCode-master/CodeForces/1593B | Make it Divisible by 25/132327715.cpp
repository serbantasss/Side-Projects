#include <cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,n0=0,n5=0,n2=0,n7=0,nr=0,ok=0;
        scanf("%lld",&x);
        if(x%25==0)
        {
            printf("0\n");
            continue;
        }
        while(x>0)
        {
            if(x%10==0)
            {
                n0++;
                if(n0>1)
                {
                    ok=1;
                    break;
                }
            }
            if(x%10==2)
            {
                n2++;
                if(n5)
                {
                    ok=1;
                    break;
                }
            }
            if(x%10==5)
            {
                n5++;
                if(n0)
                {
                    ok=1;
                    break;
                }
            }
            if(x%10==7)
            {
                n7++;
                if(n5)
                {
                    ok=1;
                    break;
                }
            }
            nr++;
            x/=10;
        }
        if(ok)
            printf("%lld\n",nr-1);
        else
            printf("%lld\n",nr);
    }
    return 0;
}