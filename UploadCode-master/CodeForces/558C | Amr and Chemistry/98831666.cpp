#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#define x first
#define y second
using namespace std;
int v[100005],f[100005],ans[100005];
queue<pair<int,int> >q;
int main()
{
    int n,x,minn=1000000005;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        q.push({x,0});
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            if(t.x>100005)
                continue;
            if(f[t.x]==i)
                continue;
            f[t.x]=i;
            v[t.x]++;
            ans[t.x]+=t.y;
            q.push({t.x/2,t.y+1});
            q.push({t.x*2,t.y+1});
        }
    }
    for(int i=1;i<100005;++i)
        if(v[i]==n && ans[i]<minn)
            minn=ans[i];
    printf("%d",minn);
    return 0;
}