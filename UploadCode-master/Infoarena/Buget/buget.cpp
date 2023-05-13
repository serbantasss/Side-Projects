#include <cstdio>
using namespace std;
long long int v[100005],n;
long long int sum(int lim)
{
    long long int s=0;
    for(int i=1;i<=n;++i)
        if(v[i]>=lim)
            s+=lim;
        else
            s+=v[i];
    return s;
}
int main()
{
    freopen("buget.in","r",stdin);
    freopen("buget.out","w",stdout);
    long long int i,j,st=1,dr=0,c;
    long long int b,s,smax=0;
    scanf("%lld%lld",&n,&b);
    for(i=1;i<=n;++i)
    {
        scanf("%lld",&v[i]);
        if(dr<v[i])
            dr=v[i];
    }
    int mid;
    while(st<=dr)
    {
        mid=(st+dr)/2;
        s=sum(mid);
        if(s>b)
            dr=mid-1;
        else
        {
            st=mid+1;
            c=mid;
        }
    }
    printf("%lld",c);
    return 0;
}