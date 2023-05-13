#include <cstdio>
#include <vector>
using namespace std;
int f[105];
vector<int>v;
int main()
{
    int n,i,j,k,x;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        if(f[x]==0)
        {
            v.push_back(i);
            f[x]=1;
        }
    }
    if(v.size()<k)
        printf("NO");
    else
    {
        printf("YES\n");
        for(i=0;i<k;++i)
            printf("%d ",v[i]);
    }
    return 0;
}