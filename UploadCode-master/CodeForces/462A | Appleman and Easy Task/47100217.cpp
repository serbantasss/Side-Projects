#include <cstdio>
#include <string>
using namespace std;
bool v[105][105];
int main()
{
    int n,i,j;
    char ch;
    scanf("%d\n",&n);
    for(i=1;i<=n;++i)
    {
        scanf("\n");
        for(j=1;j<=n;++j)
        {
            scanf("%ch",&ch);
            if(ch=='o')
                v[i][j]=1;
        }
    }
 
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if((v[i+1][j]+v[i-1][j]+v[i][j+1]+v[i][j-1])%2==1)
    {
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}