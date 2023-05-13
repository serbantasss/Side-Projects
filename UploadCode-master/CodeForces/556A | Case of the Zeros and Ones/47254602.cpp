#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,n,i,x1=0,x0=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%1d",&x);
        if(x==1)
            x1++;
        else
            x0++;
    }
    printf("%d",abs(x1-x0));
    return 0;
}