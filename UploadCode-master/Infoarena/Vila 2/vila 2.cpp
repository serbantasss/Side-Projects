#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;
struct myint
{
    int x,y;
};
deque<myint>  qmax,q;
int v[100001];
int main()
{
    freopen("vila2.in","r",stdin);
    freopen("vila2.out","w",stdout);
    int i,n,k,dif,max=0;
    myint a;
    scanf("%d %d",&n,&k);
    k++;
    for(i=1; i<=n; ++i)
        scanf("%d",&v[i]);
    for(i=1; i<=n; ++i)
    {
        while(!q.empty() && q.back().x>=v[i])
            q.pop_back();
        while(!q.empty() && i-q.front().y+1>k)
            q.pop_front();
        a.x=v[i];
        a.y=i;
        q.push_back(a);
        while(!qmax.empty() && qmax.back().x<=v[i])
            qmax.pop_back();
        while(!qmax.empty() && i-qmax.front().y+1>k)
            qmax.pop_front();
        a.x=v[i];
        a.y=i;
        qmax.push_back(a);
        if(i>=k)
        {
            if(max<qmax.front().x-q.front().x)
                max=qmax.front().x-q.front().x;
        }
    }
    printf("%d",max);
    return 0;
}