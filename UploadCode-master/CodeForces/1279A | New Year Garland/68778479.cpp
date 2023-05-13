#include <bits/stdc++.h>
using namespace std;
int v[3];
int main()
{
    //freopen("furnicik.in","r",stdin);
    //freopen("furnicik.out","w",stdout);
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d%d",&v[0],&v[1],&v[2]);
        sort(v,v+3);
        if(v[2]<=1+v[0]+v[1])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}