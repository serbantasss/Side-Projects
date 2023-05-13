#include <cstdio>
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,nr=0,maxx=0,x;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&x);
            nr+=x;
            if(x>maxx)
                maxx=x;
        }
        if(maxx>nr/2 || nr%2==1)
            printf("T\n");
        else
            printf("HL\n");
    }
    return 0;
}