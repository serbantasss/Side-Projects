#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int h[100005], n, m, q;
long long pars[100005];
struct intt
{
 int x,y;
}stj,drs;
inline int binarySearch(int left, int rigt, int value)
{
    int mid, answer = left - 1;
    while(left <= rigt)
    {
        mid = (left + rigt) / 2;
        if(h[mid] < value)
        {
            answer = mid;
            left = mid + 1;
        }
        else
            rigt = mid - 1;
    }
    return answer;
}
int main ()
{
    freopen("tnia.in","r",stdin);
    freopen("tnia.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&h[i]);
    for(int i = 1; i <= n; i++)
        pars[i] = pars[i - 1] + h[i];
    scanf("%d",&q);
    for(int i = 1; i <= q; i++)
    {
        scanf("%d%d%d%d", &stj.x, &stj.y, &drs.x, &drs.y);
        int poz1 = binarySearch(stj.x, drs.x, stj.y);
        int poz2 = binarySearch(stj.x, drs.x, drs.y);
        printf("%lld\n", pars[poz2] - pars[poz1] - ((long long)poz2 - poz1) * (stj.y - 1)+ ((long long)drs.x - poz2) * (drs.y - stj.y + 1));
    }
    return 0;
}