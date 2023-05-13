#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    freopen("cal.in","r",stdin);
    freopen("cal.out","w",stdout);
    int i,j,s,n,x,y,nr=0;
    scanf("%d%d%d%d",&i,&j,&s,&n);
    for(;n;--n)
    {
        scanf("%d%d",&x,&y);
        if(abs(i-x)+abs(y-j)==s)
            nr++;
    }
    printf("%d",nr);
    return 0;
}