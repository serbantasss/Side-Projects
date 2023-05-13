#include <cstdio>
using namespace std;
int r[1005];
bool dp[1005],viz[1005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>m)
    {
        printf("YES");
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&r[i]);
        r[i]=r[i]%m;
    }
    for(int i=1;i<=n;++i)
    {
        for(int rest=0;rest<m;++rest)
            if((rest-r[i]+m)%m==0 || dp[(rest-r[i]+m)%m]==1)
                viz[rest]=1;
        for(int rest=0;rest<m;++rest)
            if(viz[rest]==1)
                dp[rest]=1;
    }
    if(viz[0]==1)
        printf("YES");
    else
        printf("NO");
    return 0;
}