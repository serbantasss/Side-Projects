#include <bits/stdc++.h>
using namespace std;
int main()
{
    //    freopen("cocochanel.in","r",stdin);
    //    freopen("cocochanel.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==1)
            printf("-1\n");
        else
        {
            n--;
            if(n%3==0)
                printf("4"),n--;
            for(int i=1;i<=n;++i)
                printf("2");
            printf("3\n");
        }
    }
    return 0;
}