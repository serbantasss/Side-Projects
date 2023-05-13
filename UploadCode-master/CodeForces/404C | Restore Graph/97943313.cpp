#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i)
    {
        int x;
        scanf("%d",&x);
        v[x].push_back(i);
    }
    if(v[0].size()!=1)
    {
        printf("-1");
        return 0;
    }
    if(v[1].size()>k)
    {
        printf("-1");
        return 0;
    }
    for(int i=2; i<n; ++i)
        if(1LL*v[i].size()>1LL*(k-1)*(1LL*v[i-1].size()))
        {
            printf("-1");
            return 0;
        }
    printf("%d\n",n-1);
    for(int i=0;i<v[1].size();++i)
        printf("%d %d\n",v[0][0],v[1][i]);
    for(int d=1;d<n-1;++d)
    {
        int m=v[d+1].size(),indm=0;
        for(int i=0;i<v[d].size();++i)
            for(int j=1;j<k && indm<m;++indm,++j)
                printf("%d %d\n",v[d][i],v[d+1][indm]);
    }
    return 0;
}