#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    //freopen("insule.in","r",stdin);
    //freopen("insule.out","w",stdout);
    long long n,k,i,sum;
    scanf("%lld%lld",&n,&k);
    for(i=0;i<=k;++i)
        v[i]=1;
    sum=k;
    for(i=k-1;i>=0;--i)
    {
        while(sum+v[i]<=n)
        {
            sum+=v[i];
            v[i]*=2;
        }
    }
    if(sum!=n)
        printf("NO");
    else
    {
        printf("YES\n");
        for(i=0;i<k;++i)
            printf("%d ",v[i]);
    }
    return 0;
}