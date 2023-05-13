#include <bits/stdc++.h>
using namespace std;
int l[100005],r[100005];
int main()
{
    int n,i;
    long long s=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d%d",&l[i],&r[i]);
    sort(l+1,l+n+1);
    sort(r+1,r+n+1);
    for(i=1;i<=n;++i)
        if(l[i]>r[i])
            s=s+(long long)l[i];
        else
            s=s+(long long)r[i];
    printf("%lld",s+(long long)n);
    return 0;
}