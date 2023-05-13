#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define t first
#define ver second
using namespace std;
vector<int> adc[55];
int ans[200005],viz[55][200005];
int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
inline int mod(int x,int cm)
{
    if(x%cm==0)
        return cm;
    return x%cm;
}
int main()
{
    freopen("albinuta.in","r",stdin);
    freopen("albinuta.out","w",stdout);
    int n,m,q,x,nod,lcod=0,lcic=0,cm=1;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&m);
        for(int j=1; j<=m; ++j)
        {
            scanf("%d",&x);
            adc[i].push_back(x);
        }
        cm=(m*cm)/cmmdc(cm,m);
    }
    x=1;
    nod=1;
    while(1)
    {
      //  printf("t=%d nod=%d\n",x,nod);

        if(viz[nod][mod(x,cm)])
        {
            lcic=x-viz[nod][mod(x,cm)];
            lcod=viz[nod][mod(x,cm)]-1;
            break;
        }
        viz[nod][mod(x,cm)]=x;
        ans[x]=nod;
        if(x%adc[nod].size()==0)
            nod=adc[nod][adc[nod].size()-1];
        else
            nod=adc[nod][x%adc[nod].size()-1];
        x++;
    }
   // printf("%d %d\n",lcod,lcic);
    for(; q; --q)
    {
        scanf("%d",&x);
        if(x<=lcod)
            printf("%d\n",ans[x]);
        else
            if((x-lcod)%lcic==0)
                printf("%d\n",ans[lcod+lcic]);
            else
                printf("%d\n",ans[lcod+(x-lcod)%lcic]);
    }
    return 0;

}