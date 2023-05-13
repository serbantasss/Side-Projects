#include <cstdio>
#include <queue>
using namespace std;
bool ma[200][200];
struct poz
{
    int x,y,pas;
};
queue<poz> q;
int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};
int main()
{
    freopen("alee.in","r",stdin);
    freopen("alee.out","w",stdout);
    int n,m,i,j,x,y,xf,yf;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        ma[x][y]=1;
    }
    scanf("%d%d%d%d",&x,&y,&xf,&yf);
    for(i=0;i<=n+1;++i)
        ma[0][i]=ma[n+1][i]=ma[i][0]=ma[i][n+1]=1;
    poz pf,p,ceg;
    p.x=x;
    p.y=y;
    p.pas=1;
    pf.x=xf;
    pf.y=yf;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        if(p.x==pf.x && p.y==pf.y)
        {
            printf("%d",p.pas);
            return 0;
        }
        ma[p.x][p.y]=1;
        q.pop();
        for(i=0;i<4;++i)
        {
            ceg.x=p.x+dirx[i];
            ceg.y=p.y+diry[i];
            ceg.pas=p.pas+1;
            if(!ma[ceg.x][ceg.y])
                {
                    q.push(ceg);
                    ma[ceg.x][ceg.y]=1;
                }
        }
    }
    return 0;
}