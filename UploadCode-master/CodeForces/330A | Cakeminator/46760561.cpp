#include <bits/stdc++.h>
 
using namespace std;
char mat[100][100];
int main()
{
    int r,c,rn=0,cn=0,i,j;
    char ch;
    scanf("%d%d",&r,&c);
    for(i=1; i<=r; ++i)
    {
        scanf("\n");
        for(j=1; j<=c; ++j)
            scanf("%c",&mat[i][j]);
    }
    for(i=1; i<=r; ++i)
        for(j=1; j<=c; ++j)
            if(mat[i][j]=='S')
            {
                rn++;
                break;
            }
    for(j=1; j<=c; ++j)
        for(i=1; i<=r; ++i)
            if(mat[i][j]=='S')
            {
                cn++;
                break;
            }
    printf("%d",r*c-rn*cn);
    return 0;
}