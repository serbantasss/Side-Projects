#include <bits/stdc++.h>
using namespace std;
long long BIT[1000005],v[1000005],st[1000005],dr[1000005];
void update(long long i, long long inc, long long n) {
 
    while (i <n) {
 
        BIT[i] += inc;
        i += (i & (-i));
    }
}
 
long long query(long long i) {
 
    long long ans = 1;
    while (i > 0) {
 
        ans += BIT[i];
        i -= (i & (-i));
    }
    return ans;
}
int main()
{
 
    long long n;
    scanf("%lld",&n);
    unordered_map<long long,long long>pre,suff;
    for(long long i=1;i<=n;i++)
        scanf("%lld",&v[i]);
    for(long long i=1;i<=n;i++)
    {
        pre[v[i]]++;
        st[i]=pre[v[i]];
    }
    for(long long i=n;i>=1;i--)
    {
        suff[v[i]]++;
        dr[i]=suff[v[i]];
    }
 
    long long ans=0;
    for(long long i=1;i<=n;i++){
 
        ans+=i-query(dr[i]);
        update(st[i],1,n);
    }
    printf("%lld",ans);
    return 0;
}