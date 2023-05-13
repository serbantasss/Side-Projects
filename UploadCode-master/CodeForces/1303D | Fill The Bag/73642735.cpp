#include <bits/stdc++.h>
using namespace std;
int f[1000];
map<long long,int> mp;
int main()
{
    //    freopen("cocochanel.in","r",stdin);
    //    freopen("cocochanel.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1,x=0;i<=1000000000;i*=2,x++)
        mp[i]=x;
    while(t--)
    {
        long long n,k,desp=0,cn;
        bool ok=1;
        scanf("%lld%lld",&n,&k);
        cn=n;
        for(int i=1;i<=k;++i)
        {
            long long x;
            scanf("%lld",&x);
            f[mp[x]]++;
        }
        for(long long mask=0;(1LL<<mask)<=n;++mask)
        {
            if((1LL<<mask)&n)
            {
                if(f[mask])
                    f[mask]--;
                else
                {
                    while(1)
                    {
                        long long cmask=mask+1;
                        while(!f[cmask] && cmask<=100)
                            cmask++;
                        if(cmask>=100)
                        {
                            ok=0;
                            break;
                        }
                        desp++;
                        f[cmask]--;
                        f[cmask-1]+=2;
                        if(f[mask])
                            break;
                    }
                    if(!ok)
                        break;
                    f[mask]--;
                }
            }
            f[mask+1]+=f[mask]/2;
            f[mask]=0;
        }
        for(int i=0;i<=100;++i)
            f[i]=0;
        if(ok)
            printf("%lld\n",desp);
        else
            printf("-1\n");
    }
    return 0;
}