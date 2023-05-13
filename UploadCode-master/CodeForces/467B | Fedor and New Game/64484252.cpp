#include <bits/stdc++.h>
using namespace std;
bool v[1005][30];
int main()
{
    //freopen("insule.in","r",stdin);
    //freopen("insule.out","w",stdout);
    int n,k,m,david,ans=0,x,mask;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&x);
        for(int j=0,mask=1;mask<=x;mask=mask<<1,j++)
            v[i][j]=x&mask;
    }
    scanf("%d",&david);
    for(int j=0,mask=1;mask<=david;mask=mask<<1,j++)
        v[m+1][j]=david&mask;
    for(int i=1;i<=m;++i)
    {
        int nrdif=0;
        for(int j=0;j<=n;++j)
            if(v[i][j]!=v[m+1][j])
                nrdif++;
        if(nrdif<=k)
            ans++;
    }
    printf("%d",ans);
    return 0;
}