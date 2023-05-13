#include <cstdio>
#include <algorithm>
using namespace std;
int p[105],s[105],c[105];
int main()
{
   // freopen("spargere2.in","r",stdin);
   // freopen("spargere2.out","w",stdout);
    int n,m,i,j,k,ans=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i)
        scanf("%d",&p[i]);
    for(i=1;i<=n;++i)
        scanf("%d",&s[i]);
    for(i=1;i<=k;++i)
        scanf("%d",&c[i]);
    for(i=1;i<=k;++i)
        {
            int ok=0;
            for(j=1;j<=n;++j)
                if(s[j]==s[c[i]] && p[j]>p[c[i]])
                    ok=1;
            if(ok)
                ans++;
        }
    printf("%d",ans);
    return 0;
}