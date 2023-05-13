#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct punct
{
    int x,y;
};
struct muchie
{
    int x,y;
    double cost;
    friend bool operator<(const muchie& l, const muchie& r)
    {
        return l.cost<r.cost;
    }
    friend bool operator==(const muchie& l, const muchie& r)
    {
        return l.cost==r.cost;
    }
};
vector<muchie> afis,afis2;
punct v[1005];
int rang[1005],tata[1005];
int gasestetata(int nod)
{
    int tatasuprem=nod;
    while(tata[tatasuprem]!=tatasuprem)
        tatasuprem=tata[tatasuprem];
    return tatasuprem;
}
void ceapa(int a,int b)//ceapa....onion....union...haha....flotari
{
    if(rang[a]==rang[b])
    {
        tata[b]=a;
        rang[a]++;
    }
    else
        if(rang[a]>rang[b])
            tata[b]=a;
        else
            tata[a]=b;
}
int main()
{
    freopen("desen.in","r",stdin);
    freopen("desen.out","w",stdout);
    int n,i,j;
    scanf("%d",&n);
    scanf("%d%d",&v[1].x,&v[1].y);
    printf("0.000000\n");
    for(i=2;i<=n;++i)
    {
        scanf("%d%d",&v[i].x,&v[i].y);
        for(j=1;j<i;++j)
        {
            tata[j]=j;
            rang[j]=1;
            muchie pb;
            pb.x=i;
            pb.y=j;
            pb.cost=sqrt((double)(v[i].x-v[j].x)*(v[i].x-v[j].x)+(v[i].y-v[j].y)*(v[i].y-v[j].y));
            afis.push_back(pb);
        }
        tata[i]=i;
        rang[i]=1;
        sort(afis.begin(),afis.end());
        double cost=0.0;
        afis2.clear();
        for(j=0;j<afis.size();j++)
        {
            int rx,ry;
            rx=gasestetata(afis[j].x);
            ry=gasestetata(afis[j].y);
            if(rx!=ry)
            {
                ceapa(rx,ry);
                cost+=afis[j].cost;
                afis2.push_back(afis[j]);
            }
        }
        printf("%lf\n",cost);
        afis=afis2;
    }
    return 0;
}