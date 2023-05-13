#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
vector<pair<int,int> >adc[100005];
int cost[100005],mcost=0;
void dfs(int nod,int tata)
{
    if(nod!=1 && adc[nod].size()==1)
        mcost=max(cost[nod],mcost);
    for(int i=0; i<adc[nod].size(); ++i)
        if(adc[nod][i].x!=tata)
        {
            cost[adc[nod][i].x]=adc[nod][i].y+cost[nod];
            dfs(adc[nod][i].x,nod);
        }
}
int main()
{
    int n;
    long long sum=0;
    scanf("%d",&n);
    for(int i=1; i<n; ++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adc[a].push_back({b,c});
        adc[b].push_back({a,c});
        sum+=c;
    }
    sum*=2;
    dfs(1,0);
    printf("%lld",sum-1LL*mcost);
    return 0;
}