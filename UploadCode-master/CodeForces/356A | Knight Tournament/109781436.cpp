#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int nmax=300005;
int tata[nmax],ans[nmax];
int n,m=1,f;
int findtata(int nod)
{
    if(tata[nod]==nod)
        return nod;
    return tata[nod]=findtata(tata[nod]);
}
int main()
{
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    scanf("%d%d",&n,&f);
    for(int i=1;i<=n+1;++i)
        tata[i]=i;
    for(int i=1;i<=f;++i)
    {
        int x,y,win,t;
        scanf("%d%d%d",&x,&y,&win);
        t=findtata(x);
        while(t<=y)
        {
            if(t==win)
                t++;
            else
            {
                ans[t]=win;
                tata[t]=t+1;
            }
            t=findtata(t);
        }
    }
    for(int i=1;i<=n;++i)
        printf("%d ",ans[i]);
    return 0;
}