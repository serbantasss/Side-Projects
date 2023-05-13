#include <cstdio>
 
using namespace std;
int v[200005];
int main()
{
    int n,i;
    scanf("%d",&n);
    if(n%2==0)
        printf("NO");
    else
    {
        printf("YES\n");
        int x=1;
        for(i=1;i<=n;++i)
            if(i%2==1)
            {
                v[i]=x;
                x++;
                v[i+n]=x;
                x++;
            }
            else
            {
                v[i+n]=x;
                x++;
                v[i]=x;
                x++;
            }
        for(i=1;i<=2*n;++i)
            printf("%d ",v[i]);
    }
    return 0;
}