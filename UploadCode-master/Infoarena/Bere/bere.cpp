#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
long long int v[15005],s[30005];
int main()
{
    freopen("br.in","r",stdin);
    freopen("br.out","w",stdout);
    long long int n,i,t,j,st,dr,mid,k,suma,cate;
    scanf("%lld%lld",&n,&t);
    for(i=1;i<=n;++i)
        {
            scanf("%lld",&v[i]);
            s[i]=s[i-1]+v[i];
        }
    for(i=1;i<=n;++i)
        s[i+n]=s[i+n-1]+v[i];
    for(;t;--t)
    {
        scanf("%lld%lld",&k,&suma);
        if(suma<s[k]-s[k-1])
        {
            printf("0\n");
            continue;
        }
        st=k;
        dr=n+k-1;
        cate=1;
        while(st<=dr)
        {
            mid=(st+dr)/2;
            if(s[mid]-s[k-1]<=suma)
                cate=mid,st=mid+1;
            else
                dr=mid-1;
        }
        printf("%lld\n",cate-k+1);
    }
    return 0;
}