#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int f[100005];
int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&k);
        a[k]=i;
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&k);
        b[k]=i;
    }
    for(int i=1;i<=n;++i)
        f[b[i]]=a[i];
    for(int i=1;i<=n;++i)
        printf("%d ",f[i]);
    return 0;
}