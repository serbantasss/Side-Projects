#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int mat[205][205];
pair<int,int> v1[40005],v2[40005];
vector<int> adc[40005];
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
int n,m,g,k,sx,sy,l,ans,viz[40005],out[50005];
void ina(int x,int y)
{
    if( x>=1 && y>=1 && x<=n && y<=m)
        mat[x][y]=-1;
}
void cerinta1()
{
    for(int i=0; i<=n+1; ++i)
        mat[i][0]=mat[i][m+1]=-1;
    for(int i=0; i<=m+1; ++i)
        mat[0][i]=mat[n+1][i]=-1;
    if(mat[sx][sy]==-2)
        return;
    queue<pair<int,int> >q;
    q.push({sx,sy});
    mat[sx][sy]=1;
    while(!q.empty())
    {
        pair<int,int> t=q.front();
        q.pop();
        for(int d=0; d<4; ++d)
        {
            if(mat[t.x+dx[d]][t.y+dy[d]]==-2)
            {
                sx=t.x+dx[d];
                sy=t.y+dy[d];
                l=mat[t.x][t.y];
                return;
            }
            if(mat[t.x+dx[d]][t.y+dy[d]]==0)
                q.push({t.x+dx[d],t.y+dy[d]}),mat[t.x+dx[d]][t.y+dy[d]]=mat[t.x][t.y]+1;
        }
    }
}
void euler(int x)
{
    int cur,next;
    while(adc[x].size()!=0)
    {
        cur=adc[x].back();
        adc[x].pop_back();
        if(viz[cur]==0)
        {
            viz[cur]=1;
            if(((v1[cur].x-1)*m+v1[cur].y)==x)
                next=(v2[cur].x-1)*m+v2[cur].y;
            else
                next=(v1[cur].x-1)*m+v1[cur].y;
            euler(next);
        }
    }
    out[++ans]=x;
}
int main()
{
    freopen("cartite.in","r",stdin);
    freopen("cartite.out","w",stdout);
    int c;
    scanf("%d%d%d%d%d%d",&c,&n,&m,&sx,&sy,&g);
    for(int i=1; i<=g; ++i)
    {
        int x,y,r;
        scanf("%d%d%d",&x,&y,&r);
        if(r==0)
            ina(x,y);
        if(r==1)
            ina(x,y),ina(x,y+1),ina(x,y-1),ina(x+1,y),ina(x-1,y);
        if(r==2)
            ina(x,y),ina(x,y+1),ina(x,y-1),ina(x+1,y),ina(x-1,y), ina(x+1,y+1),ina(x-1,y-1),ina(x+1,y-1),ina(x-1,y+1), ina(x,y+2),ina(x,y-2),ina(x+2,y),ina(x-2,y);
    }
    scanf("%d",&k);
    for(int i=1; i<=k; ++i)
    {
        int x,y,z,t;
        scanf("%d%d%d%d",&x,&y,&z,&t);
        v1[i].x=x,v1[i].y=y;
        v2[i].x=z,v2[i].y=t;
        if(mat[x][y]==0)
            mat[x][y]=-2;
        if(mat[z][t]==0)
            mat[z][t]=-2;
        adc[(x-1)*m+y].push_back(i);
        adc[(z-1)*m+t].push_back(i);
    }
    cerinta1();
    if(c==1)
        printf("%d %d %d\n",sx,sy,l);
    else
    {
        euler((sx-1)*m+sy);
        for(;ans>=1;ans--)
            printf("%d %d\n",(out[ans]-1)/m+1,(out[ans]-1)%m+1);
    }
    return 0;
}