#include <bits/stdc++.h>
using namespace std;
bool maskuri[100005][62];
vector<long long> v;
int viz[100005];
vector<int> ma[100005];
int rtrn=INT_MAX;
void bfs(int ind)
{
    queue<int> q,adan;
    q.push(ind);
    adan.push(1);
    viz[ind]=1;
    while(!q.empty())
    {
        ind=q.front();
        q.pop();
        int h=adan.front();
        adan.pop();
        for(int i=0;i<ma[ind].size();++i)
            if(viz[ma[ind][i]])
            {
                if(viz[ma[ind][i]]!=viz[ind]-1 && rtrn>h+viz[ma[ind][i]]-1)
                    rtrn=h+viz[ma[ind][i]]-1;
                continue;
            }
            else
            {
                viz[ma[ind][i]]=h+1;
                q.push(ma[ind][i]);
                adan.push(h+1);
            }
    }
}
int main()
{
    int n,i,j;
    long long x,p;
    scanf("%d",&n);
    v.push_back(0);
    for(i=1;i<=n;++i)
    {
        scanf("%lld",&x);
        if(x)
        {
            v.push_back(x);
        for(p=1,j=0;p<=x;p=p<<1,j++)
            if(x&p)
                maskuri[v.size()-1][j]=1;
            else
                maskuri[v.size()-1][j]=0;
        }
    }
    bool ok=1;
    for(j=0;j<=62 && ok;++j)
    {
        int nr=0;
        for(i=1;i<=v.size()-1;++i)
            nr+=maskuri[i][j];
        if(nr>=3)
            ok=0;
    }
    if(!ok)
    {
        printf("3");
        return 0;
    }
    for(i=1;i<=v.size()-1;++i)
        for(j=i+1;j<=v.size()-1;++j)
            if(v[i]&v[j])
                ma[i].push_back(j),ma[j].push_back(i);
    for(i=1;i<=v.size()-1;++i)
        if(v[i])
        {
            memset(viz,0,sizeof(viz));
            bfs(i);
        }
    if(rtrn!=INT_MAX)
        printf("%d",rtrn);
    else
        printf("-1");
    return 0;
}