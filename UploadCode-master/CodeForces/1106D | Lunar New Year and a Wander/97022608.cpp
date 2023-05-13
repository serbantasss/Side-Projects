#include <bits/stdc++.h>
using namespace std;
set<int>af;
map<int,bool>viz;
vector<int>adc[100005];
int main()
{
    int n,m,nod=1;
    scanf("%d%d",&m,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        adc[x].push_back(y);
        adc[y].push_back(x);
    }
    af.insert(1);
    while(!af.empty())
    {
        nod=*af.begin();
        viz[nod]=1;
        af.erase(nod);
        printf("%d ",nod);
        for(int i=0;i<adc[nod].size();++i)
            if(viz[adc[nod][i]]==0)
                af.insert(adc[nod][i]);
    }
    return 0;
}