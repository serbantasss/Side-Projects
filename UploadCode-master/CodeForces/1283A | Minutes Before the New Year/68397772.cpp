#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("furnicik.in","r",stdin);
    //freopen("furnicik.out","w",stdout);
    int n,x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",(23-x)*60+60-y);
    }
    return 0;
}