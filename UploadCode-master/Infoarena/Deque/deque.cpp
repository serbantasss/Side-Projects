#include <cstdio>
#include <queue>
using namespace std;
struct myint
{
    int x,y;
};
deque<myint>  q;
int v[5000010];
int main()
{
    freopen("deque.in","r",stdin);
    freopen("deque.out","w",stdout);
   long long int i,n,k,max;
    myint a;
    scanf("%d %d",&n,&k);
    for(i=1; i<=n; ++i)
        scanf("%d",&v[i]);
    max=0;
    for(i=1; i<=n; ++i)
    {
        while(!q.empty() && q.back().x>=v[i])
            q.pop_back();
        while(!q.empty() && i-q.front().y+1>k)
            q.pop_front();
        a.x=v[i];
        a.y=i;
        q.push_back(a);
        if(i>=k)
            max=max+q.front().x;
    }
    printf("%lld",max);
    return 0;
}