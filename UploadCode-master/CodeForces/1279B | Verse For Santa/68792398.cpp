#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("furnicik.in","r",stdin);
    //freopen("furnicik.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,s,st=0,ima,ma=0,x,sum=0;
        scanf("%lld%lld",&n,&s);
        for(long long int i=1;i<=n;++i)
        {
            scanf("%lld",&x);
            if(x>ma)
                ima=i,ma=x;
            sum+=x;
            if(sum-ma<=s)
                st=ima;
            if(sum<=s)
                st=0;
        }
        printf("%lld\n",st);
    }
    return 0;
}