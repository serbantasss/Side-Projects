#include <bits/stdc++.h>
#define min(a,b) a<b? a: b
using namespace std;
const int inf=INT_MAX;
const int nmax=5005;
struct edge
{
    int x,y;
    long long f,c;
};
int n,m,st,dr,lvl[nmax],viz[nmax];
long long lim,flow;
vector<edge> mch;
vector<int> adc[nmax];
queue<int> q;
void addedge(int x,int y,int c)
{
    edge temp;

    temp.x=x;
    temp.y=y;
    temp.c=c;
    temp.f=0;
    adc[x].push_back(mch.size());
    mch.push_back(temp);

    temp.x=y;
    temp.y=x;
    temp.c=c;
    temp.f=c;
    adc[y].push_back(mch.size());
    mch.push_back(temp);
}
bool bfs()
{
    for(int i=st; i<=dr; ++i)
        lvl[i]=inf;
    lvl[st]=0;
    q.push(st);
    while(!q.empty() && lvl[dr]==inf)
    {
        int nod=q.front();
        q.pop();
        for(int i=0; i<adc[nod].size(); ++i)
            if((mch[adc[nod][i]].c-mch[adc[nod][i]].f>=lim) && (lvl[mch[adc[nod][i]].y]==inf))
            {
                lvl[mch[adc[nod][i]].y]=lvl[nod]+1;
                q.push(mch[adc[nod][i]].y);
            }
    }
    while(!q.empty()) q.pop();
    return lvl[dr]!=inf;
}
bool dfs(int nod,int f)
{
    if(f==0)
        return 0;
    if(nod==dr)
        return 1;
    for(; viz[nod]<adc[nod].size(); ++viz[nod])
        //int u = mch[adc[nod][i]].y;
        if(lvl[nod]+1==lvl[mch[adc[nod][viz[nod]]].y] && mch[adc[nod][viz[nod]]].c-mch[adc[nod][viz[nod]]].f>=f)
        {
            bool ret=dfs(mch[adc[nod][viz[nod]]].y,f);
            if(ret==0)
                continue;
            mch[adc[nod][viz[nod]]].f+=f;
            mch[adc[nod][viz[nod]] ^ 1].f-=f;
            return 1;
        }
    return 0;
}
long long flux(int a,int b)
{
    st=a,dr=b;
    flow=0;
    for(lim=(1<<30); lim>=1;)
    {
        if(!bfs())
        {
            lim>>=1;
            continue;
        }
        for(int i=0; i<=n; ++i)
            viz[i]=0;
        while(long long ret=dfs(st,lim))
            flow+=lim;
    }
    return flow;
}
int main()
{
    freopen("maxflow.in","r",stdin);
     freopen("maxflow.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; ++i)
    {
        int  x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        addedge(x,y,c);
    }
    flux(1,n);
    printf("%lld",flow);
    return 0;
}