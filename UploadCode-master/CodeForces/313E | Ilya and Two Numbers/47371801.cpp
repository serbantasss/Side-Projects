#include <cstdio>
#include <stack>
using namespace std;
int f1[100005],f2[100005],fin[100005];
stack<int>q;
int main()
{
    int n,i,j,x,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        f1[x]++;
    }
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        f2[m-x-1]++;
    }
    for(i=0;i<m;++i)
    {
        while(f1[i])
            q.push(i),f1[i]--;
        while(f2[i] && q.size())
            fin[(q.top()+m-i-1)%m]++,f2[i]--,q.pop();
    }
    for(i=0;i<m;++i)
    {
        while(f1[i])
            q.push(i),f1[i]--;
        while(f2[i] && q.size())
            fin[(q.top()+m-i-1)%m]++,f2[i]--,q.pop();
    }
    for(i=m-1;i>=0;--i)
        while(fin[i])
            printf("%d ",i),fin[i]--;
    return 0;
}