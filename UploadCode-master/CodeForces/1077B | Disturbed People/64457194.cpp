#include <bits/stdc++.h>
using namespace std;
int v[105];
int main()
{
    //freopen("insule.in","r",stdin);
    //freopen("insule.out","w",stdout);
    int n,i,nr=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d",&v[i]);
    for(int i=2;i<n;++i)
        if(v[i]==0 && v[i-1]==1 && v[i+1]==1)
        {
            nr++;
            v[i+1]=0;
        }
    printf("%d",nr);
    return 0;
}