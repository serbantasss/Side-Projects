#include <bits/stdc++.h>
 
using namespace std;
int mat[200][200];
int main()
{
    int n,k,i,j,change,maj=0;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n/k;++i)
        for(j=1;j<=k;++j)
            scanf("%d",&mat[i][j]);
    for(j=1;j<=k;++j)
    {
        int nr1=0,nr2=0;
        for(i=1;i<=n/k;++i)
            if(mat[i][j]==1)
                nr1++;
            else
                nr2++;
        if(nr1>nr2)
            maj+=nr2;
        else
            maj+=nr1;
    }
    printf("%d",maj);
    return 0;
}