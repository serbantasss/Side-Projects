#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    int n,i,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    k=1;
    for(i=1;i<=n;++i)
        if(v[i]>=k)
            k++;
    printf("%d",k-1);
    return 0;
}