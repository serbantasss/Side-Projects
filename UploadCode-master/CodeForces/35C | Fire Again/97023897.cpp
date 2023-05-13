#include <bits/stdc++.h>
using namespace std;
int mat[2005][2005],n,m,k,oi,oj,ma;
int dx[]= {0,0,-1,1};
int dy[]= {-1,1,0,0};
inline bool check(int x,int y)
{
    return (x>0 && x<n+1 && y>0 && y<m+1);
}
void bfs(int x,int y)
{
    queue<pair<int,int> >q;
    q.push({x,y});
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0; i<4; ++i)
            if(check(x+dx[i],y+dy[i]) &&(mat[x+dx[i]][y+dy[i]]==0 ||mat[x+dx[i]][y+dy[i]]>mat[x][y]+1))
            {
                mat[x+dx[i]][y+dy[i]]=mat[x][y]+1;
                q.push({x+dx[i],y+dy[i]});
            }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(; k; k--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        mat[x][y]=1;
        bfs(x,y);
    }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(mat[i][j]>ma)
                ma=mat[i][j],oi=i,oj=j;
    printf("%d %d",oi,oj);
    return 0;
}