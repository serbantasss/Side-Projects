#include <cstdio>
using namespace std;
bool f[1005];
int main()
{
    int n,mi=1000,ma=0,i,x,nr=0,mij;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        if(f[x]==0)
            f[x]=1,nr++;
        if(x>ma)
            ma=x;
        if(x<mi)
            mi=x;
    }
    for(i=0; i<=1000; ++i)
        if(i!=mi && i!=ma && f[i])
            mij=i;
    if(n==1)
        printf("0");
    if(n==2)
        if((ma-mi)%2==0)
            printf("%d",(ma-mi)/2);
        else
            printf("%d",ma-mi);
    if(n>2)
    {
        if(nr>3)
            printf("-1");
        else if(nr==2)
        {
            if((ma-mi)%2==0)
                printf("%d",(ma-mi)/2);
            else
                printf("%d",ma-mi);
        }
        else if(nr==1)
            printf("0");
        else
        {
            if(mij-mi!=ma-mij)
                printf("-1");
            else
                printf("%d",(ma-mi)/2);
        }
    }
    return 0;
}