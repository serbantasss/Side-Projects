#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
bool viz[50005],poz[50005];
pair<int,int> v[50005];
vector<int> adc[15];
vector<int> afis;
void dfs(int nr,int m)
{
    while(adc[nr].size())
    {
        int k=adc[nr].back();
        adc[nr].pop_back();
        if(!viz[k])
        {
            viz[k]=1;
            if(nr==v[k].x)
                poz[k]=1,dfs(v[k].y,k);
            else
                dfs(v[k].x,k);
        }
    }
    afis.push_back(m);
}
int main()
{
    freopen("domino.in","r",stdin);
    freopen("domino.out","w",stdout);
    int n,k,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&v[i].x,&v[i].y);
        adc[v[i].x].push_back(i);
        adc[v[i].y].push_back(i);
    }
    k=v[n].x;
    for(int i=0;i<=9;++i)
        if(adc[i].size()%2==1)
            cnt++,k=i;
    if(cnt>0 && cnt!=2)
        printf("0\n");
    else
    {
        dfs(k,0);
        if(afis.size()!=n+1)
            printf("0\n");
        else
        {
           printf("1\n");
            for(int i=0;i<afis.size()-1;++i)
                printf("%d %d\n",afis[i],poz[afis[i]]);
        }
    }
    return 0;
}