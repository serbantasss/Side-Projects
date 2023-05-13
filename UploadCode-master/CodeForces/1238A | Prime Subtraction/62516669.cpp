#include <cstdio>
#include <cstring>
using namespace std;
char mat[2005][2005];
int dp[2005];
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,y;
        scanf("%lld%lld",&x,&y);
        if(x-y>=2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}