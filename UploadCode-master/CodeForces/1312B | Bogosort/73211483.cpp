#include <bits/stdc++.h>
using namespace std;
int v[105];
int main()
{
//    freopen("cabana.in","r",stdin);
//    freopen("cabana.out","w",stdout);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&v[i]);
        sort(v+1,v+n+1);
        for(int i=n;i>=1;--i)
            printf("%d ",v[i]);
        printf("\n");
    }
    return 0;
}