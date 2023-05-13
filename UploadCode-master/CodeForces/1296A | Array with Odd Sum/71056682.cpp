#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    //freopen("disconnect.in","r",stdin);
    //freopen("disconnect.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,impar=0,par=0,x;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&x);
            if(x%2==0)
                par++;
            else
                impar++;
        }
        if(impar==0 || (impar==n && impar%2==0))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}