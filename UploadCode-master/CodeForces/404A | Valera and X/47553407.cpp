#include <bits/stdc++.h>
using namespace std;
char mat[305][305];
int main()
{
    int n,i,j;
    int ok=0;
    char d,r;
    scanf("%d\n",&n);
    for(i=1;i<=n;++i)
    {
        scanf("\n");
        for(j=1;j<=n;++j)
            scanf("%c",&mat[i][j]);
    }
    d=mat[1][1];
    r=mat[1][2];
    if(d==r)
        ok=1;
    for(i=1;i<=n;++i)
        if(mat[i][i]!=d || mat[i][n-i+1]!=d)
            ok=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if(j!=i && j!=n-i+1 && mat[i][j]!=r)
                ok=1;
    if(ok==1)
        printf("NO");
    else
        printf("YES");
    return 0;
}