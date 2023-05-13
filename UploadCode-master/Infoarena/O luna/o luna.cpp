#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    freopen("oluna.in","r",stdin);
    freopen("oluna.out","w",stdout);
    int n,i,j,x,nr=0;
    scanf("%d",&n);
    while(n)
    {
        scanf("%d",&x);
        n--;
        if(x%2==1)
        {
            printf("0\n");
            continue;
        }
        x/=2;
        if(x==1 || x==2)
        {
            printf("0\n");
            continue;
        }
        if(x==3 || x==4)
        {
            printf("1\n");
            continue;
        }
        if(x==5)
        {
            printf("2\n");
            continue;
        }
        x-=4;
        long long ans=0;
        long long x6=x/6;
        if(x%6>=1)
            ans=ans+(x6+1);
        if(x%6>=2)
            ans=ans+(x6+1);
        if(x%6>=3)
            ans=ans+(x6+1);
        if(x%6>=4)
            ans=ans+(x6+1);
        if(x%6>=5)
            ans=ans+(x6+2);
        ans=ans+1LL*5*x6*(x6+1)/2+1LL*(x6+1)*(x6+2)/2;
        printf("%lld\n",ans);
    }
    return 0;
}