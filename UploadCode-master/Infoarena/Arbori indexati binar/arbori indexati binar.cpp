///03.04.2017
#include <cstdio>
using namespace std;
int aib[100005],aibSize;
void add(int poz, int val)
{
    do
    {
        aib[poz] += val;
        poz += poz & (-poz);
    }while(poz <= aibSize);
}
int sum(int poz)
{
    int ans = 0;
    while(poz)
    {
        ans += aib[poz];
        poz -= poz & (-poz);
    }
    return ans;
}
int search(int st, int dr, int val)
{
    int mij, x;
    while(st <= dr)
    {
        mij = (st + dr) / 2;
        x = sum(mij);
        if(x == val)
            return mij;
        else if(x > val)
            dr = mij - 1;
        else
            st = mij + 1;
    }
    return -1;
}
int main()
{
    freopen("aib.in","r",stdin);
    freopen("aib.out","w",stdout);
    int n,m,i,op,a,b = 0,ans;
    scanf("%d %d",&n,&m);
    aibSize = n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        add(i,a);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&op,&a);
        if(op != 2)
            scanf("%d",&b);
        if(op == 0)
            add(a,b);
        else
        {
            if(op == 1)
                ans = sum(b) - sum(a - 1);
            else
                ans = search(1,n,a);
            printf("%d\n",ans);
        }
    }
    return 0;
}