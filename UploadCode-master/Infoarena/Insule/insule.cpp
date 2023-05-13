#include <bits/stdc++.h>
using namespace std;
queue<pair<int,int> >q;
int n,m,v[101][101],f[101][101],l[101][101],ins[4],ma=999999999;
int dx[] = {1, 0 , -1, 0};
int dy[] = {0, 1, 0, -1};

bool ok1(int x, int y, int z)
{
    if(x<1 || y<1 || x>n || y>m)
        return false;
    if(f[x][y]==z)
        return false;
    return true;
}

bool ok2(int x, int y)
{
    if(x<1 || y<1 || x>n || y>m)
        return false;
    return true;
}
void Fill(int x, int y, int z)
{
    int i,nx,ny;
    f[x][y]=z;
    for(i=0;i<4;i++)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(ok1(nx,ny,z) && v[nx][ny]==z)
            Fill(nx,ny,z);
    }
}
void Lee()
{
    int i,j,x,y,nx,ny;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(v[i][j]=='1')
            {
                l[i][j]=-1;
                q.push({i,j});
            }
            else
                if(v[i][j] == '2')
                    l[i][j] = -2;
                else
                    if(v[i][j] == '3')
                        l[i][j] = -3;
        }
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(i=0;i<4;i++)
        {
            nx=x+dx[i];
            ny=y+dy[i];
            if(ok2(nx,ny) && l[nx][ny]==0)
            {
                if(l[x][y]==-1)
                    l[nx][ny]=1;
                else
                    l[nx][ny]=l[x][y]+1;
                q.push({nx, ny});
            }
            else
                if(ok2(nx,ny) && l[nx][ny]==-2)
                    if(ma>l[x][y] && l[x][y]!=-1)
                        ma=l[x][y];
        }
    }
}

int main()
{
    freopen("insule.in","r",stdin);
    freopen("insule.out","w",stdout);
    int i,j;
    char ch;
    scanf("%d%d\n",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("\n");
        for(j=1;j<=m;j++)
        {
            scanf("%c",&ch);
            v[i][j]=(int)ch;
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(!f[i][j])
            {
                ins[v[i][j]-48]++;
                Fill(i,j,v[i][j]);
            }
    for(i=1;i<=3;i++)
        printf("%d ",ins[i]);
    Lee();
    printf("%d",ma);
    return 0;
}