#include <cstdio>
using namespace std;
bool mi[55][55];
bool mat[55][55],aux,auxm[55][55];
void roteste_matricea(int c)
{
    int i,j;
    for(i=1; i<=c; i++)
        for(j=1; j<=c; j++)
            auxm[c-j+1][i]=mat[i][j];
    for(i=1; i<=c; i++)
        for(j=1; j<=c; j++)
            mat[i][j]=auxm[i][j];
}
bool verifica(int c)
{
    int i,j;
    for(i=1; i<=c; ++i)
        for(j=1; j<=c; ++j)
            if(mat[i][j]!=mi[i][j])
                return 0;
    return 1;
}
void oglindeste(int c)
{
    int i,j;
    for(i=1; i<=c; ++i)
        for(j=1; j<=c/2; ++j)
        {
            aux=mat[i][j];
            mat[i][j]=mat[i][c-j+1];
            mat[i][c-j+1]=aux;
        }
}
int main()
{
    freopen("cartele.in","r",stdin);
    freopen("cartele.out","w",stdout);
    int n,i,j,t,c,x,y;
    scanf("%d%d",&c,&n);
    for(i=1; i<=c; ++i)
        for(j=1; j<=c; ++j)
            scanf("%d",&mi[i][j]);
    for(t=1; t<=n; ++t)
    {
        bool ok=1;
        for(i=1; i<=c; ++i)
            for(j=1; j<=c; ++j)
                {
                scanf("%d",&mat[i][j]);
                if(mat[i][j]!=mi[i][j])
                    ok=0;
                }
        if(ok)
        {
            printf("1\n");
            continue;
        }
        //r1
        roteste_matricea(c);
        if(verifica(c))
            {
            printf("1\n");
            continue;
            }
         //r2
        roteste_matricea(c);
        if(verifica(c))
            {
            printf("1\n");
            continue;
            }
         //r3
        roteste_matricea(c);
        if(verifica(c))
            {
            printf("1\n");
            continue;
            }
        //o
        oglindeste(c);
        if(verifica(c))
            {
            printf("1\n");
            continue;
            }
        //r1
        roteste_matricea(c);
        if(verifica(c))
            {
            printf("1\n");
            continue;
            }
         //r2
        roteste_matricea(c);
        if(verifica(c))
            {
            printf("1\n");
            continue;
            }
         //r3
        roteste_matricea(c);
        if(verifica(c))
            {
            printf("1\n");
            continue;
            }
        else
            printf("0\n");
    }
    return 0;
}