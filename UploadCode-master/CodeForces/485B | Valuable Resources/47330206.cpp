#include <cstdio>
 
using namespace std;
const int intmax=1000000000;
long long max(long long a,long long b)
{
    if(a>b)
        return a;
    return b;
}
long long min(long long a,long long b)
{
    if(a>b)
        return b;
    return a;
}
int main()
{
    int n;
    long long mal=-intmax,mac=-intmax,mil=intmax,mic=intmax,x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld%lld",&x,&y);
        mal=max(mal,x);
        mil=min(mil,x);
        mac=max(mac,y);
        mic=min(mic,y);
    }
    mac=mac-mic;
    mal=mal-mil;
    printf("%lld",max(mac*mac,mal*mal));
    return 0;
}