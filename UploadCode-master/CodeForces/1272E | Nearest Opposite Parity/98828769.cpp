#include <cstdio>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;
queue<pair<int,int> > q;
vector<int> adc[200005];
int a[200005],viz[200005],dist[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        if(i-a[i]>0)
            adc[i-a[i]].push_back(i);
        if(i+a[i]<n+1)
            adc[i+a[i]].push_back(i);
    }
    for(int i=1;i<=n;++i)
    {
        dist[i]=-1;
        if(a[i]%2==0)
            q.push({i,0}),viz[i]=1;
    }
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(int i=0;i<adc[t.x].size();++i)
            if(!viz[adc[t.x][i]])
            {
                if(a[adc[t.x][i]]%2==1)
                    dist[adc[t.x][i]]=t.y+1;
                q.push({adc[t.x][i],t.y+1});
                viz[adc[t.x][i]]=1;
            }
    }
    while(!q.empty())
        q.pop();
    for(int i=1;i<=n;++i)
    {
        viz[i]=0;
        if(a[i]%2==1)
            q.push({i,0}),viz[i]=1;
    }
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(int i=0;i<adc[t.x].size();++i)
            if(!viz[adc[t.x][i]])
            {
                if(a[adc[t.x][i]]%2==0)
                    dist[adc[t.x][i]]=t.y+1;
                q.push({adc[t.x][i],t.y+1});
                viz[adc[t.x][i]]=1;
            }
    }
    for(int i=1;i<=n;++i)
        printf("%d ",dist[i]);
    return 0;
}