#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
bool prim(int x)
{
    for(int d=2; d*d<=x; ++d)
        if(x%d==0)
            return 0;
    return 1;
}
int urmprim(int p1)
{
    if(prim(p1))
        return p1;
    else
        urmprim(p1+2);
}
int main()
{
    freopen("sipet.in","r",stdin);
    freopen("sipet.out","w",stdout);
    int p1,p2,p3,n,c1,c2,c3,cn,ccn,a1,a2,a3,t,r;
    scanf("%d",&t);
    for(; t; t--)
    {
        scanf("%d%d",&n,&p1);
        if(p1==2)
            p2=3,p3=5;
        else
        {
            p2=urmprim(p1+2);
            p3=urmprim(p2+2);
        }
        int mi=10000005,ma=0,rest=1;
        for(c1=n/p1; c1>=0; c1--)
        {
            cn=n-c1*p1;
            for(c2=cn/p2; c2>=0; c2--)
            {
                ccn=cn-p2*c2;
                r=ccn%p3;
                c3=ccn/p3;
                if(p1*c1+p2*c2+p3*c3>ma)
                    ma=p1*c1+p2*c2+p3*c3,a1=c1,a2=c2,a3=c3,rest=r;
                if(rest==0)
                    break;
            }
            if(rest==0)
                    break;
        }
        printf("%d %d %d %d %d\n",a1+a2+a3,a1,a2,a3,n-ma);
    }
    return 0;
}