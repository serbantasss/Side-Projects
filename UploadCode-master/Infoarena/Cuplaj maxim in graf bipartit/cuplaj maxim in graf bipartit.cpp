#include <bits/stdc++.h>
using namespace std;
int fiu[10005],tata[10005],n,m,e,ans=0;
bool viz[10005];
vector<int> adc[10005];
inline void zero()
{
    for(int i=1;i<=10005;++i)
        viz[i]=0;
}
bool cuplaj(int nod)
{
    if(viz[nod])
        return 0;
    viz[nod]=1;
    for(int i=0;i<adc[nod].size();++i)
        if(tata[adc[nod][i]]==0 || cuplaj(tata[adc[nod][i]]))
        {
            fiu[nod]=adc[nod][i];
            tata[adc[nod][i]]=nod;
            return 1;
        }
    return 0;
}
int main()
{
    freopen("cuplaj.in","r",stdin);
    freopen("cuplaj.out","w",stdout);
    scanf("%d%d%d",&n,&m,&e);
    for(int i=1;i<=e;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        adc[x].push_back(y);
//        adc[y+n].push_back(x);
    }
    while(1)
    {
        bool ok=0;
        zero();
        for(int i=1;i<=n;++i)
            if(fiu[i]==0 && cuplaj(i) )
            {
                ans++;
                ok=1;
            }
        if(!ok)
            break;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;++i)
        if(fiu[i])
            printf("%d %d\n",i,fiu[i]);
    return 0;
}