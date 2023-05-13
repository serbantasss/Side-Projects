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
        if(x<y)
        {
            if(x<=y/2)
                printf("%d\n",x);
            else
                printf("%d\n",y/2);
        }
        else
        {
            if(x%y<=y/2)
                printf("%d\n",x);
            else
                printf("%d\n",(x/y)*y+y/2);
        }
    }
    return 0;
}