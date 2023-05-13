#include <cstdio>
using namespace std;
int mat[105][105];
int masca[105][105];
int k=0,f,pnt,pntx,pnty;
int dx[]= {0,0,-1,1};
int dy[]= {-1,1,0,0};
void umpl(int x,int y)
{
    if(mat[x][y]==3)
        f++;
    if(mat[x][y]==2)
        pnt++,pntx=x,pnty=y;
    masca[x][y]=k;
    for(int i=0; i<4; ++i)
    {
        int x1,y1;
        x1=x+dx[i];
        y1=y+dy[i];
        if(mat[x1][y1]!=4 && masca[x1][y1]==0)
            umpl(x1,y1);
    }
}
int main()
{
    freopen("marceland.in","r",stdin);
    freopen("marceland.out","w",stdout);
    int t,n,m,i,j;
    char ch;
    scanf("%d",&t);
    for(; t; --t)
    {
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; ++i)
        {
            scanf("\n");
            for(j=1; j<=m; ++j)
            {
                scanf("%c",&ch);
                if(ch=='#')
                    mat[i][j]=4;
                if(ch=='.')
                    mat[i][j]=2;
                if(ch=='@')
                    mat[i][j]=3;
                if(ch=='M')
                    mat[i][j]=1;
                masca[i][j]=0;
            }
        }
        for(i=1; i<=n; ++i)
            mat[i][0]=mat[i][m+1]=4;
        for(j=1; j<=m; ++j)
            mat[0][j]=mat[n+1][j]=4;
        int ok=1,sch=0;
        k=0;
        for(i=1; i<=n &&ok ; ++i)
            for(j=1; j<=m && ok; ++j)
                if(mat[i][j]==1 && masca[i][j]==0)
                {
                    f=0;
                    k++;
                    pnt=0;
                    umpl(i,j);
                    if(f==0 && pnt==0)
                    {
                        ok=0;
                        break;
                    }
                    if(f==0 && pnt>=1)
                        mat[pntx][pnty]=3,sch++;
                }
        if(ok==0)
            {
            printf("-1\n");
            continue;
            }
        printf("%d\n",sch);
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=m; ++j)
            {
                if(mat[i][j]==4)
                    printf("#");
                if(mat[i][j]==3)
                    printf("@");
                if(mat[i][j]==2)
                    printf(".");
                if(mat[i][j]==1)
                    printf("M");
            }
            printf("\n");
        }
    }
    return 0;
}