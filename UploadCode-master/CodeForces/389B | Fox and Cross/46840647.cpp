#include <bits/stdc++.h>
#define INF 1LL<<40
typedef long long LL;
using namespace std;
bool mat[105][105];
char ch;
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("\n");
        for(j=1; j<=n; ++j)
        {
            scanf("%c",&ch);
            if(ch=='#')
                mat[i][j]=1;
        }
    }
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            if(mat[i][j]==1)
            {
                if((mat[i][j]==mat[i+1][j])&&(mat[i+1][j]==mat[i+1][j-1])&&(mat[i+1][j-1]==mat[i+1][j+1])&&(mat[i+1][j-1]==mat[i+2][j]))
                    mat[i][j]=mat[i+1][j]=mat[i+1][j+1]=mat[i+1][j-1]=mat[i+2][j]=0;
            }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if(mat[i][j]==1)
            {printf("NO");
            return 0;}
    printf("YES");
    return 0;
}