#include <bits/stdc++.h>
using namespace std;
long long dp[1<<19][105];
int cif[25],nrcif,f[15];
int main()
{
    long long n,m,mask,i,j;
    scanf("%lld%lld",&n,&m);
    do
    {
        cif[++nrcif]=n%10;
        n/=10;
    }while(n);
    dp[0][0]=1;
    for(mask=0;mask<(1<<nrcif);++mask)
    {
        for(i=0;i<=9;++i)
            f[i]=0;
        for(i=1;i<=nrcif;++i)
        {
            if(mask&(1<<(i-1)) || f[cif[i]])
                continue;
            if(mask==0 && !cif[i])
                continue;
            f[cif[i]]=1;
            for(j=0;j<m;++j)
                dp[mask|(1<<(i-1))][(j*10+cif[i])%m]+=dp[mask][j];
        }
    }
    printf("%lld",dp[(1<<(nrcif))-1][0]);
    return 0;
}