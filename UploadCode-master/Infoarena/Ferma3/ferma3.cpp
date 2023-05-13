#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int size[405*405+5],viz[405][405],k=0,vizz[405*405+5];
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
char mat[405][405];
void dfs(int x,int y)
{
    viz[x][y]=k;
    size[k]++;
    for(int i=0;i<4;++i)
    {
        int x1=x+dx[i],y1=y+dy[i];
        if(mat[x][y]==mat[x1][y1] && viz[x1][y1]==0)
            dfs(x1,y1);
    }
}
int main()
{
    freopen("ferma3.in", "r", stdin);
    freopen("ferma3.out", "w", stdout);
    int cer,n,m,ma=0,x,y;
    char c;
    scanf("%d%d%d",&cer,&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("\n");
        for(int j=1;j<=m;++j)
            scanf("%c",&mat[i][j]);
    }
    for(int i=0;i<=n+1;++i)
        viz[i][0]=viz[i][m+1]=405*405-1;
    for(int j=0;j<=m+1;++j)
        viz[0][j]=viz[n+1][j]=405*405-1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(viz[i][j]==0)
            {
                k++;
                dfs(i,j);
                if(ma<size[k])
                    ma=size[k];
            }
    if(cer==1)
    {
        printf("%d",ma);
        return 0;
    }
    ma=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            char ch=mat[i][j];
            for(int k=0;k<4;++k)
            {
                mat[i][j]=mat[i+dx[k]][j+dy[k]];
                int sz=0;
                for(int l=0;l<4;++l)
                    if(mat[i][j]==mat[i+dx[l]][j+dy[l]] && !vizz[viz[i+dx[l]][j+dy[l]]])
                        sz+=size[viz[i+dx[l]][j+dy[l]]],vizz[viz[i+dx[l]][j+dy[l]]]=1;
                if(!vizz[viz[i][j]])
                    sz++;
                if(sz>ma)
                    ma=sz,x=i,y=j,c=mat[i][j];
                for(int l=0;l<4;++l)
                    vizz[viz[i+dx[l]][j+dy[l]]]=0;
            }
            mat[i][j]=ch;
        }
    printf("%d %d\n%c",x,y,c);
    return 0;
}