#include <cstdio>
#include <algorithm>
using namespace std;
int mat1[1005][1005],mat2[1005][1005];
int main()
{
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            scanf("%d",&mat1[i+j][i]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            scanf("%d",&mat2[i+j][i]);
    for(i=1;i<=n+m;++i)
    {
        sort(mat1[i]+1,mat1[i]+n+1);
        sort(mat2[i]+1,mat2[i]+n+1);
        for(j=1;j<=n;++j)
            if(mat1[i][j]==mat2[i][j])
                continue;
            else
            {
                printf("NO");
                return 0;
            }
    }
    printf("YES");
    return 0;
}