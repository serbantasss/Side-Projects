#include <bits/stdc++.h>
using namespace std;
bool adc[1005][1005];
bool viz[1005];
int d[1005][2];
void bfs(int nod,int ind)
{
    queue<int> q;
    q.push(nod);
    viz[nod]=1;
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(int i=1;i<=1000;++i)
            if(!viz[i] && adc[nod][i])
            {
                viz[i]=1;
                d[i][ind]=d[nod][ind]+1;
                q.push(i);
            }
    }
}
int main()
{
    int n,m,st,dr,ans=0;
    scanf("%d%d%d%d",&n,&m,&st,&dr);
    for(int i=1; i<=m; ++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        adc[x][y]=adc[y][x]=1;
    }
    bfs(st,0);
    for(int i=1;i<=n;++i)
        viz[i]=0;
    bfs(dr,1);
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            if(!adc[i][j] && d[i][0]+d[j][1]+1>=d[st][1] && d[j][0]+d[i][1]+1>=d[dr][0])
                ans++;
    printf("%d",ans);
    return 0;
}