#include <cstdio>
using namespace std;
int v[105];
int main()
{
    int n,i,j,poz=0,neg=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
        if(v[i]<0)
            neg++;
        if(v[i]>0)
            poz++;
    }
    if(n%2==1)
        n++;
    if(poz>=n/2)
        printf("1");
    else
        if(neg>=n/2)
            printf("-1");
        else
            printf("0");
    return 0;
}