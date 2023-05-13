#include <bits/stdc++.h>
using namespace std;
int f[10000005];
int main()
{
    int n,x,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        {
            scanf("%d",&x);
            f[x]++;
        }
    for(x=0;x<=10000000;x++)
    {
        f[x+1]+=f[x]/2;
        if(f[x]%2==1)
            ans++;
    }
    printf("%d",ans);
    return 0;
}