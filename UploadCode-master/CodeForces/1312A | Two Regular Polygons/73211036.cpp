#include <bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("cabana.in","r",stdin);
//    freopen("cabana.out","w",stdout);
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n%m==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}