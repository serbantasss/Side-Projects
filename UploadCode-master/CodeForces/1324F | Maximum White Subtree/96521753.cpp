#include <bits/stdc++.h>
using namespace std;
vector<int>adc[200005];
int ans[200005],dp[200005];
bool semn[200005],viz[200005];
inline int pm(bool x)
{
    if(x==0)
        return -1;
    return 1;
}
void dfs(int nod,int tata)
{
    dp[nod]=pm(semn[nod]);
    for(int i=0; i<adc[nod].size(); ++i)
        if(adc[nod][i]!=tata)
        {
            dfs(adc[nod][i],nod);
            dp[nod]=dp[nod]+max(dp[adc[nod][i]],0);
        }
}
void rez(int rad)
{
    viz[rad]=1;
    for(int i=0;i<adc[rad].size();++i)
        if(!viz[adc[rad][i]])
        {
            dp[rad]-=max(dp[adc[rad][i]],0);
            dp[adc[rad][i]]+=max(dp[rad],0);
            ans[adc[rad][i]]=dp[adc[rad][i]];
            //printf("%d ",dp[adc[rad][i]]);
            rez(adc[rad][i]);
            dp[adc[rad][i]]-=max(dp[rad],0);
            dp[rad]+=max(dp[adc[rad][i]],0);
        }
}
int main()
{
    //freopen("poly.in","r",stdin);
    //freopen("poly.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%d",&semn[i]);
    for(int i=1; i<n; ++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        adc[x].push_back(y);
        adc[y].push_back(x);
    }
    dfs(1,1);
    ans[1]=dp[1];
    rez(1);
    for(int i=1;i<=n;++i)
        printf("%d ",ans[i]);
    return 0;
}