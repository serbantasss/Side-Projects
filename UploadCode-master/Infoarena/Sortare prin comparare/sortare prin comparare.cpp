#include <cstdio>
#include <algorithm>
using namespace std;
int v[500005];
int main()
{
    freopen("algsort.in","r",stdin);
    freopen("algsort.out","w",stdout);
    int n,q;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    for(int i=1; i<=n; ++i)
        printf("%d ",v[i]);
    return 0;
}