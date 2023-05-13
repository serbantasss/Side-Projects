#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
char s[105];
int main()
{
    //freopen("spargere2.in","r",stdin);
    //freopen("spargere2.out","w",stdout);
    int i,n,x,y;
    scanf("%d",&n);
    scanf("%d",&x);
    for(i=2; i<=n; ++i)
    {
        scanf("%d",&y);
        if(abs(x-y)>=2)
        {
            printf("NO");
            return 0;
        }
        x=y;
    }
    printf("YES");
    return 0;
}