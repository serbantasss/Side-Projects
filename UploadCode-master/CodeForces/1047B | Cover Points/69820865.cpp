#include <bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("cabana.in","r",stdin);
//    freopen("cabana.out","w",stdout);
    int n,i,x,y,ma=-1;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&x,&y);
        if(ma<x+y)
            ma=x+y;
    }
    printf("%d",ma);
    return 0;
}