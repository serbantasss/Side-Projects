#include <bits/stdc++.h>
using namespace std;
int v[200005],fii[200005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,nr=1;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&v[i]),fii[i]=0;
        fii[2]=fii[nr]+1;
        for(int i=3;i<=n;++i)
            {
                if(v[i-1]>v[i])
                    nr++;
                fii[i]=fii[nr]+1;
            }
        printf("%d\n",fii[n]);
    }
    return 0;
}