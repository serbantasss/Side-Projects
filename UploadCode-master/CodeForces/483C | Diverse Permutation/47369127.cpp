#include <cstdio>
using namespace std;
int main()
{
    int n,i,j,k,x1,x2;
    scanf("%d%d",&n,&k);
    x1=1;
    x2=n;
    for(i=1;i<=k;i++)
        if(i%2==1)
        {
            printf("%d ",x1);
            x1++;
        }
        else
        {
            printf("%d ",x2);
            x2--;
        }
    if(k%2==1)
        for(i=k+1;i<=n;++i)
            {
                printf("%d ",x1);
                x1++;
            }
    else
        for(i=k+1;i<=n;++i)
            {
                printf("%d ",x2);
                x2--;
            }
    return 0;
}