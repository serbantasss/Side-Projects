#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int t[200005];
int main()
{
    //    freopen("1.in","r",stdin);
    //    freopen("1.out","w",stdout);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n,x;
        long long ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            t[i]=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&x);
            if(x>0)
            {
                if(i-x+1<1)
                    t[1]++;
                else
                    t[i-x+1]++;
                t[i+1]--;
            }
        }
        ans=0;
        for(int i=1;i<=n;++i)
        {
            ans+=t[i];
            if(ans>0)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}