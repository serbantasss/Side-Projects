#include <bits/stdc++.h>
 
using namespace std;
int v[200];
int main()
{
    int n,k,i,j,m,x=0;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)
        scanf("%d",&v[i]);
    scanf("%d",&m);
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
        {x=v[i];
        v[i]=v[i-1]+x;}
    if(n>=m)
    {
        printf("%d",v[m]);
    }
    else
    {
        printf("%d",v[n]-k*(m-n));
    }
    return 0;
}