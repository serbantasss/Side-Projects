#include <cstdio>
#include <algorithm>
using namespace  std;
int v[400005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,x,ans=0,pos=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k;++i)
            scanf("%d",&v[i]);
        sort(v+1,v+k+1);
        for(int i=k;i>=1;--i)
        {
            if(pos<v[i])
            {
                pos+=n-v[i];
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}