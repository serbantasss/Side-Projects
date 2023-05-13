#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;
vector<pair<int,int> > adc[10005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int cost[10005],h[10005];
bool viz[10005];
int main()
{
    freopen("cezar.in", "r", stdin);
    freopen("cezar.out", "w", stdout);
    int n,k,r=1,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        adc[x].push_back({y,i});
        adc[y].push_back({x,i});
    }
    for(int i=1;i<=n;++i)
        {
            if(adc[i].size()==1)
                q.push({1,i});
            cost[i]=1;
            h[i]=adc[i].size();
        }
    while(r<=n-k-1)
    {
        int nod=q.top().y,c=q.top().x;
        q.pop();
        ans+=c;
        viz[nod]=1;
        r++;
        for(int i=0;i<adc[nod].size();++i)
        {
            h[adc[nod][i].x]--;
            if(!viz[adc[nod][i].x])
            {
                cost[adc[nod][i].x]+=c;
                if(h[adc[nod][i].x]==1)
                    q.push({cost[adc[nod][i].x],adc[nod][i].x});
            }
        }
    }
    printf("%d",ans);
    return 0;
}