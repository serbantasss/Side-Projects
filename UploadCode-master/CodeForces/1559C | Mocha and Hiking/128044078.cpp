#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
bool v[10005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        bool o2=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&v[i]);
        v[n+1]=0;
        if(v[1]==1)
            {
                printf("%d ",n+1);
                for(int i=1;i<=n;++i)
                    printf("%d ",i);
                printf("\n");
                continue;
            }
        if(v[n]==0)
            {
                for(int i=1;i<=n;++i)
                    printf("%d ",i);
                printf("%d\n",n+1);
                continue;
            }
        for(int i=1;i<=n;++i)
            {
            printf("%d ",i);
            if(v[i]==0 && v[i+1]==1 && o2==0)
                printf("%d ",n+1),o2=1;
            }
    }
    return 0;
}