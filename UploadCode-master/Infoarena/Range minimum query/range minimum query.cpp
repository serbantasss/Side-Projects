#include <cstdio>
#include <algorithm>
using namespace std;
int v[100005],lg[100005],rmq[100005][20];
int main()
{
    freopen("rmq.in","r",stdin);
    freopen("rmq.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",&v[i]);
    lg[1]=0;
    for(int i=2;i<=n;++i)
        lg[i]=lg[i/2]+1;
    for(int i=1;i<=n;++i)
        rmq[i][0]=v[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            if(rmq[i][j-1]<rmq[i+(1<<(j-1))][j-1])
                rmq[i][j]=rmq[i][j-1];
            else
                 rmq[i][j]=rmq[i+(1<<(j-1))][j-1];
    for(;q;--q)
    {
        int x,y,k;
        scanf("%d%d",&x,&y);
        k=lg[y-x+1];
        printf("%d\n",min(rmq[x][k],rmq[y-(1<<k)+1][k]));
    }
    return 0;
}