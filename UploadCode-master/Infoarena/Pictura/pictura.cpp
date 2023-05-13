#include <bits/stdc++.h>
using namespace std;
bool viz[1005][1005];
int mat[1005][1005];
int dx[]= {0,0,-1,1};
int dy[]= {-1,1,0,0};
struct intt
{
    int z,d,i;
}v[1000005];
void fYlL(int x,int y)
{
    viz[x][y]=1;
    int v1=0,v2=0;
    for(int i=0;i<2;++i)
        if(mat[x+dx[i]][y+dy[i]]==mat[x][y])
            v1++;
    for(int i=2;i<4;++i)
        if(mat[x+dx[i]][y+dy[i]]==mat[x][y])
            v2++;
    if(v1+v2==4)
        v[mat[x][y]].i++;
    if(v1+v2==2 && v1==v2)
        v[mat[x][y]].d++;
    for(int i=0;i<4;++i)
        if(!viz[x+dx[i]][y+dy[i]]&&mat[x+dx[i]][y+dy[i]]==mat[x][y])
            fYlL(x+dx[i],y+dy[i]);
}
int main()
{
    freopen("pictura.in","r",stdin);
    freopen("pictura.out","w",stdout);
    int n,m,i,j,maxc=0,d;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            scanf("%d",&mat[i][j]);
            if(mat[i][j]>maxc)
                maxc=mat[i][j];
        }
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(!viz[i][j] && mat[i][j])
            {
                v[mat[i][j]].z++;
                fYlL(i,j);
            }
    printf("%d\n",maxc);
    for(i=1;i<=maxc;++i)
        printf("%d %d %d\n",v[i].z,v[i].d,v[i].i);
    return 0;
}