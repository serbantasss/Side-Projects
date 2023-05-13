#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct intt
{
    int d,ind;
};
intt v[105];
bool cmp(intt a,intt b)
{
    if(a.d==b.d)
        return a.ind<b.ind;
    return a.d<b.d;
}
vector<int> v1;
int main()
{
    int n,i,j=0,k,x;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        v[i].d=x;
        v[i].ind=i;
    }
    sort(v+1,v+n+1,cmp);
    x=k;
    for(i=1; i<=n; ++i)
        if(v[i].d<=x)
        {
            x-=v[i].d;
            v1.push_back(v[i].ind);
        }
        else
            break;
    sort(v1.begin(),v1.end());
    printf("%d\n",v1.size());
    for(i=0;i<v1.size();++i)
        printf("%d ",v1[i]);
    return 0;
}