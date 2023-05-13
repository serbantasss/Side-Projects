#include <bits/stdc++.h>
using namespace std;
vector<int>tati[1005];
vector<int>adc[1005];
int main()
{
    int n,m,nr=0,cost=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&m);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        tati[b].push_back(c);
    }
    for(int i=1;i<=n;++i)
        if(!tati[i].size())
            nr++;
        else
        {
            int m=1000005;
            for(int j=0;j<tati[i].size();++j)
                if(tati[i][j]<m)
                    m=tati[i][j];
            cost+=m;
        }
    if(nr>1)
        printf("-1");
    else
        printf("%d",cost);
    return 0;
}