#include <cstdio>
using namespace std;
int main()
{
    freopen("furnici.in","r",stdin);
    freopen("furnici.out","w",stdout);
    int n,l,i,j,x,maxim=-10000000;
    char ch;
    scanf("%d %d\n",&l,&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d %c\n",&x,&ch);
        if(ch=='S')
        {
            if(maxim<x)
                maxim=x;
        }
        else
        {
            if(maxim<l-x)
                maxim=l-x;
        }
    }
    printf("%d",maxim);
    return 0;
}