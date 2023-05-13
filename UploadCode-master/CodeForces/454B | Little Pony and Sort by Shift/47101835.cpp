#include <cstdio>
#include <string>
using namespace std;
int v[100005];
int main()
{
    int n,i,j;
    scanf("%lld",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
    }
    for(i=1;i<n;++i)
    {
        if(v[i]>v[i+1])
            if(v[n]<=v[1])
        {
            bool ok=1;
            for(j=i+1;j<n;++j)
                if(v[j]>v[j+1])
                    ok=0;
            if(ok==1)
                printf("%d",n-i);
            else
                printf("-1");
            return 0;
        }
        else
        {
            printf("-1");
            return 0;
        }
    }
    printf("0");
    return 0;
}