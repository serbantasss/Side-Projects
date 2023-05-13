#include <cstdio>
using namespace std;
bool mat[55][55];
int mf[55][55];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void fill(int x,int y,int k)
{
    if(mat[x][y])
        return;
    mat[x][y]=1;
    mf[x][y]=k;
    for(int d=0;d<4;++d)
        fill(x+dx[d],y+dy[d],k);
}
int main()
{
    //freopen("compact.in","r",stdin);
   // freopen("compact.out","w",stdout);
    int n,i,j,x,y,xf,yf,k=0;
    scanf("%d",&n);
    scanf("%d%d",&x,&y);
    scanf("%d%d",&xf,&yf);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            scanf("%1d",&mat[i][j]);
    for(i=0;i<=n+1;++i)
        mat[i][0]=mat[i][n+1]=mat[0][i]=mat[n+1][i]=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if(!mat[i][j])
        {
            k++;
            fill(i,j,k);
        }
    int ki=mf[x][y],kf=mf[xf][yf];
    long long tunel,mi=999999999999;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if(mf[i][j]==ki)
                for(int i1=1;i1<=n;++i1)
                    for(int j1=1;j1<=n;++j1)
                        if(mf[i1][j1]==kf)
                            {
                                tunel=1LL*(i-i1)*(i-i1)+1LL*(j-j1)*(j-j1);
                                if(tunel<mi)
                                    mi=tunel;
                            }
    printf("%d",mi);
    return 0;
}