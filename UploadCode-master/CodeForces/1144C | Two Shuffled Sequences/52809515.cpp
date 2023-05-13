#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int f[200005];
vector<int>v1;
vector<int>v2;
int main()
{
    int n,i,x;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        f[x]++;
        if(f[x]>2)
        {
            printf("NO");
            return 0;
        }
        if(f[x]==1)
            v1.push_back(x);
        if(f[x]==2)
            v2.push_back(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    printf("YES\n%d\n",v1.size());
    for(i=0;i<v1.size();++i)
        printf("%d ",v1[i]);
    printf("\n%d\n",v2.size());
    if(v2.size()==0)
        printf("\n");
    for(i=v2.size()-1;i>=0;--i)
        printf("%d ",v2[i]);
    return 0;
}