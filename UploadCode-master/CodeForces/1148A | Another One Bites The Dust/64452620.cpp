#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("insule.in","r",stdin);
    //freopen("insule.out","w",stdout);
    long long a,b,c;
    long long ans;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a==b)
        ans=2*c+a+b;
    else
        if(a<b)
            ans=2*c+2*a+1;
        else
            ans=2*c+2*b+1;
    printf("%lld",ans);
    return 0;
}