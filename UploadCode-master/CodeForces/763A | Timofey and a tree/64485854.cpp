#include <bits/stdc++.h>
using namespace std;
vector<int> adiac[100005];
int c[100005],ans;
void dfs(int nodcur,int nodtata,int cul)
{
    if(c[nodcur]!=cul)
    {
        ans=0;
        return;
    }
    for(int i=0;i<adiac[nodcur].size();++i)
        if(adiac[nodcur][i]!=nodtata)
            dfs(adiac[nodcur][i],nodcur,cul);
}
int main()
{
    //freopen("insule.in","r",stdin);
    //freopen("insule.out","w",stdout);
    int n,i,a = 0,b = 0,j;
    bool ok=1;
    scanf("%d",&n);
    for(i=1;i<=n-1;++i)
    {
        scanf("%d%d",&a,&b);
        adiac[a].push_back(b);
        adiac[b].push_back(a);
    }
    for(i=1;i<=n;++i)
        scanf("%d",&c[i]);
    for(i=1;i<=n && ok;++i)
        for(j=0;j<adiac[i].size() && ok;++j)
            if(c[i]!=c[adiac[i][j]])
            {
                a=i;
                b=adiac[i][j];
                ok=0;
            }
    if(ok)
    {
        printf("YES\n1");
        return 0;
    }
    ok=1;
    for(i=0;i<adiac[a].size() && ok;++i)
    {
        ans=1;
        dfs(adiac[a][i],a,c[adiac[a][i]]);
        if(ans==0)
            ok=0;
    }
    if(ok)
    {
        printf("YES\n%d",a);
        return 0;
    }
    ok=1;
    for(i=0;i<adiac[b].size() && ok;++i)
    {
        ans=1;
        dfs(adiac[b][i],b,c[adiac[b][i]]);
        if(ans==0)
            ok=0;
    }
    if(ok)
    {
        printf("YES\n%d",b);
        return 0;
    }
    printf("NO");
    return 0;
}