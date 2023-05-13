#include <cstdio>
using namespace std;
bool s[105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        bool st=1;
        scanf("%d",&n);
        for(int i=1;i<=2*n-1;++i)
            scanf("%1d",&s[i]);
        for(int k=1;k<=n && st;++k)
        {
            bool ok=1;
            for(int i=k;i<n+k && ok;++i)
                ok=s[i];
            if(ok)
                st=0;
        }
        if(st)
            for(int i=1;i<=n;++i)
                printf("0");
        else
            for(int i=1;i<=n;++i)
                printf("1");
        printf("\n");
    }
    return 0;
}