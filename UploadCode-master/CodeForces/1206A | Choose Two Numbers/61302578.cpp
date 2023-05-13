#include <cstdio>
 
using namespace std;
 
int main()
{
    int n,i,x,m1,m2;
    scanf("%d%d",&n,&x);
    m1=x;
    for(i=2;i<=n;++i)
    {
        scanf("%d",&x);
        if(m1<x)
            m1=x;
    }
    scanf("%d%d",&n,&x);
    m2=x;
    for(i=2;i<=n;++i)
    {
        scanf("%d",&x);
        if(m2<x)
            m2=x;
    }
    printf("%d %d",m1,m2);
    return 0;
}