#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans=0,fc,x,y,meat=0;
    scanf("%d%d%d",&n,&x,&y);
    fc=y;
    meat=x;
    for(int i=2;i<=n;++i)
    {
        scanf("%d %d",&x,&y);
        if(y<fc)
        {
            ans+=meat*fc;
            fc=y;
            meat=x;
        }
        else
            meat+=x;
    }
    ans+=meat*fc;
    printf("%d",ans);
    return 0;
}