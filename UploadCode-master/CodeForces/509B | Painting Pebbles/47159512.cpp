#include <cstdio>
 
using namespace std;
int v[105];
int main()
{
    int n,i,j,k,ma=-1,mi=10000000;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&v[i]);
        if(v[i]>ma)
            ma=v[i];
        if(v[i]<mi)
            mi=v[i];
    }
    if(ma-mi>k)
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(i=1; i<=n; i++)
    {
        j = k;
        int l = v[i];
        while(l>0)
        {
            printf("%d ",j);
            j--;
            l--;
            if(j==0)
                j=k;
        }
        printf("\n");
    }
    return 0;
}