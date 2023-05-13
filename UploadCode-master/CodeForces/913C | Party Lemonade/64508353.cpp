#include <bits/stdc++.h>
using namespace std;
int cost[35];
int main()
{
    //freopen("insule.in","r",stdin);
    //freopen("insule.out","w",stdout);
    int n,l;
    long long ans=LLONG_MAX,x=0;
    scanf("%d%d",&n,&l);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&cost[i]);
        if(i>0 && cost[i]>cost[i-1]*2)
            cost[i]=cost[i-1]*2;
    }
    for(int i=n-1;i>=0;--i)
    {
        int mask=1<<i;
        x=x+(long long)cost[i]*(l/mask);
        l=l%mask;
        if(l==0)
        {
            if(ans>x)
                ans=x;
            break;
        }
        else
            if(ans>x+cost[i])
                ans=x+cost[i];
    }
    printf("%lld",ans);
    return 0;
}