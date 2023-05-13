#include<bits/stdc++.h>
using namespace std;
 
long long v[100005];
int main()
{
    long long n,k,ans,st,dr;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&v[i]);
    sort(v+1,v+n+1);
    st=1;
    dr=n;
    ans=v[n]-v[1];
    while(st<dr && k)
    {
        long long t;
        if(st<n-dr+1)
        {
            st++;
            t=min(v[st]-v[st-1], k/(st-1));
            k=k-t*(st-1);
        }
        else
        {
            t=min(v[dr]-v[dr-1], k/(n-dr+1));
            k=k-t*(n-dr+1);
            dr--;
        }
        ans-=t;
    }
    printf("%lld", ans);
    return 0;
}