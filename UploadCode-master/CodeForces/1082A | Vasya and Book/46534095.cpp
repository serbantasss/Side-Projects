#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <climits>
 
using namespace std;
int dist(int x,int y,int d)
{
    return (abs(x-y)+d-1)/d;
}
int main()
{
    int t,n,i,x,y,d;
    scanf("%d",&t);
    for(;t;--t)
    {
        scanf("%d%d%d%d",&n,&x,&y,&d);
        int ans=INT_MAX,dxy=abs(x-y);
        if(dxy%d==0)
            ans=min(ans,dist(x,y,d));
        dxy=y-1;
        if(dxy%d==0)
            ans=min(ans,dist(1,y,d)+dist(x,1,d));
        dxy=n-y;
        if(dxy%d==0)
            ans=min(ans,dist(x,n,d)+dist(n,y,d));
        if(ans==INT_MAX)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}