#include <bits/stdc++.h>
using namespace std;
int adica[50][50];
int dp[1005][30];///cate siruri de lung n se termina cu lit da
int main()
{
    freopen("nrcuv.in","r",stdin);
      freopen("nrcuv.out","w",stdout);
    int n,m,i,j,k,nr,horse;
    char ch1,ch2;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;++i)
    {
        scanf("\n%c %c",&ch1,&ch2);
        adica[ch1-'a'+1][ch2-'a'+1]=adica[ch2-'a'+1][ch1-'a'+1]=1;
    }
    for(i=1;i<=26;++i)
        dp[1][i]=1;
    for(i=2;i<=n;++i)
        for(j=1;j<=26;++j)
            for(k=1;k<=26;++k)
                if(adica[j][k]==0)
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%104659;
    int sum=0;
    for(i=1;i<=26;++i)
        sum=(sum+dp[n][i])%104659;
    printf("%d",sum);
    return 0;
}