#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#define x first
#define y second
using namespace std;
int n,m,ni,ok;
bool mat[25][25];
pair<int,int> om[25];
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
struct misc
{
    int x,y,d;
}sol[105];
void backtracking(int poz)
{
    if(poz==ni)
    {
        for(int i=1;i<ni;++i)
            printf("%d %d %d %d\n",sol[i].x,sol[i].y,sol[i].x+2*dx[sol[i].d],sol[i].y+2*dy[sol[i].d]);
        ok=1;
        return;
    }
    for(int i=1;i<=ni;++i)
    {
        int x=om[i].x,y=om[i].y;
        if(mat[x][y])
            for(int d=0;d<4;++d)
                if((x+2*dx[d]>0 && x+2*dx[d]<=n && y+2*dy[d]>0 && y+2*dy[d]<=m) && mat[x+dx[d]][y+dy[d]] && !mat[x+2*dx[d]][y+2*dy[d]])
                {
                    mat[x][y]=mat[x+dx[d]][y+dy[d]]=0;
                    mat[x+2*dx[d]][y+2*dy[d]]=1;
                    om[i].x=x+2*dx[d];
                    om[i].y=y+2*dy[d];
                    sol[poz].x=x;
                    sol[poz].y=y;
                    sol[poz].d=d;
                    backtracking(poz+1);
                    if(ok)
                        return;
                    mat[x][y]=mat[x+dx[d]][y+dy[d]]=1;
                    mat[x+2*dx[d]][y+2*dy[d]]=0;
                    om[i].x=x;
                    om[i].y=y;
                }
    }
}
int main()
{
    freopen("immortal.in","r",stdin);
    freopen("immortal.out","w",stdout);
    scanf("%d%d%d",&n,&m,&ni);
    for(int i=1;i<=ni;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        mat[x][y]=1;
        om[i].x=x;
        om[i].y=y;
    }
    backtracking(1);
    return 0;
}