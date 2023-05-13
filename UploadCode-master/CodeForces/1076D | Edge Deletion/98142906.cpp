#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
vector<int>ans;
vector<pair<int,pair<int,int> > > adc[300005];
priority_queue<pair<long long,pair<int,int> > >q;
int f[300005];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adc[a].push_back({b,{c,i}});
        adc[b].push_back({a,{c,i}});
    }
    q.push({0,{1,0}});
    long long t,nod,ind;
    while(!q.empty())
    {
        t=-q.top().x;
        nod=q.top().y.x;
        ind=q.top().y.y;
        q.pop();
        if(f[nod])
            continue;
        f[nod]=1;
        if(nod!=1)
        {
            if(ans.size()>=k)
                break;
            ans.push_back(ind);
        }
        for(int i=0;i<adc[nod].size();++i)
            q.push({-t-adc[nod][i].y.x,{adc[nod][i].x,adc[nod][i].y.y}});
    }
    printf("%lu\n",ans.size());
    for(int i=0;i<ans.size();++i)
        printf("%d ",ans[i]);
    return 0;
}