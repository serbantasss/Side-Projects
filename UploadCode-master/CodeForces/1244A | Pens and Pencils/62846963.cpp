#include <cstdio>
using namespace std;
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int a,b,c,d,k,x,y;
    int t;
    scanf("%d",&t);
    for(;t;t--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(a%c==0)
            x=a/c;
        else
            x=a/c+1;
        if(b%d==0)
            y=b/d;
        else
            y=b/d+1;
        if(x+y<=k)
            printf("%d %d\n",x,y);
        else
            printf("-1\n");
    }
    return 0;
}