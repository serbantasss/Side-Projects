#include <cstdio>
#include <algorithm>
using namespace std;
long long int v[100005];
int main()
{
    freopen("furnicik.in","r",stdin);
    freopen("furnicik.out","w",stdout);
    long long int n,i,t,l,p,s,x;
    scanf("%lld%lld%lld",&n,&l,&t);
    for(i=1;i<=n;++i)
    {
        scanf("%lld%lld",&p,&s);
        if(s==0)
        {
            x=p-t;
            if(x<0)
                x=-x;
            if((x/l)%2==1)
                v[i]=l-(x%l);
            else
                v[i]=x%l;
        }
        else
        {
            x=l-t-p;
            if(x<0)
                x=-x;
            if((x/l)%2==0)
                v[i]=l-(x%l);
            else
                v[i]=x%l;
        }
    }
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
        printf("%d ",v[i]);
    return 0;
}