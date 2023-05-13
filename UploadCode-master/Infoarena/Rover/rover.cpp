#include <bits/stdc++.h>
using namespace std;
int n,g,mat[505][505],viz[505][505];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct fmm
{
    int x,y,g;
};
bool verif(int gmax)
{
    queue<fmm> q;
    q.push({1,1,0});
    viz[1][1]=gmax;
    viz[n][n]=-1;
    while(!q.empty())
    {
        fmm t=q.front();
        q.pop();
        for(int i=0;i<4;++i)
            if(t.x+dx[i]>0 && t.x+dx[i]<n+1 && t.y+dy[i]>0 && t.y+dy[i]<n+1 && viz[t.x+dx[i]][t.y+dy[i]]!=gmax && mat[t.x+dx[i]][t.y+dy[i]]>=gmax)
            {
                viz[t.x+dx[i]][t.y+dy[i]]=gmax;
                q.push({t.x+dx[i],t.y+dy[i],0});
            }
    }
    return viz[n][n]!=-1;
}
int main()
{
        freopen("rover.in", "r", stdin);
        freopen("rover.out", "w", stdout);
    int cer;
    scanf("%d",&cer);
    if(cer==1)
    {
        scanf("%d%d",&n,&g);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                scanf("%d",&mat[i][j]);
        deque< fmm > q;
        q.push_back({1,1,1});
        while(!q.empty())
        {
            fmm t=q.front();
            q.pop_front();
            for(int i=0;i<4;++i)
                if(t.x+dx[i]>0 && t.x+dx[i]<n+1 && t.y+dy[i]>0 && t.y+dy[i]<n+1)
                {
                    fmm pu=t;
                    pu.x=t.x+dx[i];
                    pu.y=t.y+dy[i];
                    if(mat[pu.x][pu.y]<g)
                        pu.g++;
                    if(!viz[pu.x][pu.y])
                    {
                        viz[pu.x][pu.y]=pu.g;
                        if(mat[pu.x][pu.y]>=g)
                            q.push_front(pu);
                        else
                            q.push_back(pu);
                    }
                    else
                        if(viz[pu.x][pu.y]>pu.g)
                        {
                            viz[pu.x][pu.y]=pu.g;
                            if(mat[pu.x][pu.y]>=g)
                                q.push_front(pu);
                            else
                                q.push_back(pu);
                        }
                }
            if(t.x==n && t.y==n)
                break;
        }
        printf("%d",viz[n][n]-1);
    }
    else
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                scanf("%d",&mat[i][j]);
        int st=1,dr=10000,mid,ans=-1;
        while(st<=dr)
        {
            mid=(st+dr)/2;
            if(verif(mid))
                ans=mid,st=mid+1;
            else
                dr=mid-1;
        }
        printf("%d",ans);
    }
    return 0;
}