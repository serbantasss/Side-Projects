#include <cstdio>
#include <queue>
using namespace std;
int mat[105][105];
int dp[105][105][105];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
    freopen("homm.in","r",stdin);
    freopen("homm.out","w",stdout);
    int n,m,k,i,j,x,y,xf,yf;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            scanf("%d",&mat[i][j]);
    scanf("%d%d%d%d",&x,&y,&xf,&yf);
    dp[x][y][0]=1;
    for(int kk=1;kk<=k;++kk)
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                if(mat[i][j]==0)
                    for(int p=0;p<4;++p)
                        if(mat[i+dx[p]][j+dy[p]]==0 && i+dx[p]>0 && i+dx[p]<=n && j+dy[p]>0 && j+dy[p]<=m)
                            dp[i][j][kk]+=dp[i+dx[p]][j+dy[p]][kk-1];
    int s=0;
    for(i=0;i<=k;++i)
        s+=dp[xf][yf][i];
    printf("%d",s);
    return 0;
}