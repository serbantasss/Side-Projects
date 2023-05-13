#include <bits/stdc++.h>
using namespace std;
int tarc[505*505][2];
bool ac[505][505];
int dist[505][505];
int dx[]= {1,0,-1,0};
int dy[]= {0,-1,0,1};
struct fmm
{
    int x,y;
};
bool mamacojo(int cod,int k,int s)
{
    for(int i=0; i<s; ++i)
        if(((1<<i)&cod)==((1<<i)&k))
            return 0;
    return 1;
}
void lee(int x,int y)
{
    queue<fmm> q;
    q.push({x,y});
    dist[x][y]=1;
    while(!q.empty())
    {
        fmm t=q.front();
        q.pop();
        for(int i=0; i<4; ++i)
            if(!dist[t.x+dx[i]][t.y+dy[i]] && ac[t.x+dx[i]][t.y+dy[i]])
                    {
                        dist[t.x+dx[i]][t.y+dy[i]]=dist[t.x][t.y]+1;
                        q.push({t.x+dx[i],t.y+dy[i]});
                    }
    }
}
int main()
{
    freopen("panda.in","r",stdin);
    freopen("panda.out","w",stdout);
    //(1<<s)-(k|mat[i][j])
    int n,m,s,k,px,py,cer,t,ans1=0;
    scanf("%d%d%d%d%d%d%d%d",&cer,&n,&m,&t,&px,&py,&k,&s);
    for(int i=1; i<=t; ++i)
        scanf("%d%d",&tarc[i][0],&tarc[i][1]);
    //printf("%d",mamacojo(15,1,1));
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            int cod;
            scanf("%d",&cod);
            ac[i][j]=mamacojo(cod,k,s);
            if(ac[i][j] && !(i==px && j==py))
                ans1++;
        }
    if(cer==1)
    {
        printf("%d",ans1);
        return 0;
    }
    else
    {
        lee(px,py);
        int mi=INT_MAX,nrmi=0;
        for(int i=1; i<=t; ++i)
            if(mi>dist[tarc[i][0]][tarc[i][1]] && dist[tarc[i][0]][tarc[i][1]])
                mi=dist[tarc[i][0]][tarc[i][1]],nrmi=1;
            else if(mi==dist[tarc[i][0]][tarc[i][1]])
                nrmi++;
        printf("%d %d",mi-1,nrmi);
    }
    return 0;
}