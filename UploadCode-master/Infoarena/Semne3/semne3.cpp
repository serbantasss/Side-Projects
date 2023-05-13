#include <cstdio>
using namespace std;
char s[500010];
int n;
int main()
{
    freopen("semne3.in", "r", stdin);
    freopen("semne3.out", "w", stdout);
    int i,j,k;
    scanf("%d\n", &n);
    for(i=1;i<=n;++i)
        scanf("%c",&s[i]);
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(s[j-1]=='<')
                break;
        }
        for(k=j-1;k>=i;k--)
        {
            printf("%d ", k);
        }
        i=j-1;
    }
    return 0;
}