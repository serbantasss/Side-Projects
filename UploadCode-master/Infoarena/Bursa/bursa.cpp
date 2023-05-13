#include <cstdio>
using namespace std;
long long v[100005];
int main()
{
    freopen("bursa.in","r",stdin);
    freopen("bursa.out","w",stdout);
    int n,i;
    long long s,nrac,stot;
    scanf("%d%lld",&n,&s);
    stot=s;
    for(i=1; i<=n; ++i)
        scanf("%lld",&v[i]);
    for(i=1;i<=n;++i)
    {
        if(v[i]<v[i+1])
        {
            nrac=s/v[i];
            s-=nrac*v[i];
            while(v[i]<=v[i+1])
                i++;
            s=s+nrac*v[i];
        }
    }
    printf("%lld",s-stot);
    return 0;
}