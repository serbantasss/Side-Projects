#include <bits/stdc++.h>
 
using namespace std;
bool f[100005];
int v[100005],ans[100005];
int main()
{
    int n,m,i,j,x;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; ++i)
        scanf("%d",&v[i]);
    for(i=n; i>=1; --i)
        if(f[v[i]]==0)
        {
            f[v[i]]=1;
            ans[i]=ans[i+1]+1;
        }
        else
            ans[i]=ans[i+1];
    for(;m;--m)
    {
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return 0;
}