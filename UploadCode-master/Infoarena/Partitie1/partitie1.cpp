#include <cstdio>
#include <algorithm>
using namespace std;
int mat[1005][1005];
int resturi[1005];
int main()
{
    freopen("partitie1.in","r",stdin);
     freopen("partitie1.out","w",stdout);
    int n,i,j,x;
    scanf("%d",&n);
    i=0;
    for(x=1; x<=n; x+=2)
        resturi[i++]=x;
    for(x=2; x<=n; x+=2)
        resturi[i++]=x;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            mat[i][j]=resturi[(i+j-2)%n]+(i-1)*n;
    for(j=1; j<=n; ++j)
    {
        for(i=1; i<=n; ++i)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    return 0;
}