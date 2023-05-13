#include <bits/stdc++.h>
using namespace std;
vector<int> adc[100005];
int p[100005],h[100005],v[100005];
bool viz[100005];
void dfs1(int nod)
{
    viz[nod]=1;
    v[nod]=p[nod];
    for(int i=0; i<adc[nod].size(); ++i)
        if(!viz[adc[nod][i]])
        {
            dfs1(adc[nod][i]);
            v[nod]+=v[adc[nod][i]];
        }
}
bool dfs2(int nod)
{
    viz[nod]=1;
    bool ok=1;
    int x=0;
    for(int i=0; i<adc[nod].size(); ++i)
        if(!viz[adc[nod][i]])
        {
            ok=ok*dfs2(adc[nod][i]);
            x+=h[adc[nod][i]];
        }
    return (x<=h[nod]) && ok;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        bool ok=1;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; ++i)
            scanf("%d",&p[i]),viz[i]=0;
        for(int i=1; i<=n; ++i)
            scanf("%d",&h[i]);
        for(int i=1; i<n; ++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            adc[x].push_back(y);
            adc[y].push_back(x);
        }
        dfs1(1);
        for(int i=1; i<=n && ok; ++i)
            if((v[i]+h[i])%2)
                ok=0;
            else
                h[i]=(v[i]+h[i])/2;
        if(!ok)
        {
            printf("NO\n");
            for(int i=1; i<=n; ++i)
                adc[i].clear();
            continue;
        }
        for(int i=1; i<=n && ok; ++i)
        {
            if(v[i]<h[i])
                ok=0;
            viz[i]=0;
        }
        if(!ok)
        {
            printf("NO\n");
            for(int i=1; i<=n; ++i)
                adc[i].clear();
            continue;
        }
        ok=dfs2(1);
        if(!ok)
        {
            printf("NO\n");
            for(int i=1; i<=n; ++i)
                adc[i].clear();
            continue;
        }
        printf("YES\n");
        for(int i=1; i<=n; ++i)
            adc[i].clear();
    }
    return 0;
}