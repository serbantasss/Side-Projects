#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int cnt[200005],ccnt[200005];
int main()
{
//    freopen("sediu.in","r",stdin);
//    freopen("sediu.out","w",stdout);
    int n,maxx=0,indm;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&v[i]);
    for(int i=1;i<=n;++i)
    {
        for(int b=0;b<64;++b)
            if(!(v[i]%(1LL<<b)))
                cnt[i]++;
            else
                break;
        ccnt[cnt[i]]++;
        if(ccnt[cnt[i]]>maxx)
        {
            maxx=ccnt[cnt[i]];
            indm=i;
        }
    }
    printf("%d\n",n-maxx);
    for(int i=1;i<=n;++i)
        if(cnt[i]!=cnt[indm])
            printf("%lld ",v[i]);
    return 0;
}