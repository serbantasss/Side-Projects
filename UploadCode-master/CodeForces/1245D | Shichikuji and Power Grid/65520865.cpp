#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
};
point v[2005];
long long c[2005],k[2005],tata[2005];
bool viz[2005];
vector<int>powerstation;
vector<pair<int,int>>pipes;
long long distmanhattan(int p1,int p2)
{
    return (long long)abs(v[p1].x-v[p2].x)+(long long)abs(v[p1].y-v[p2].y);
}
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int n,i,pas;
    long long cost=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d%d",&v[i].x,&v[i].y);
    for(i=1;i<=n;++i)
        scanf("%d",&c[i]);
    for(i=1;i<=n;++i)
        scanf("%d",&k[i]);
    for(i=1;i<=n;++i)
        tata[i]=i;
    pas=n;
    while(pas>0)
    {
        long long psmin=LLONG_MAX;
        int poz;
        for(i=1;i<=n;++i)
            if(viz[i])
                continue;
            else
                if(c[i]<psmin)
                    psmin=c[i],poz=i;
        if(tata[poz]==poz)
            powerstation.push_back(poz);
        else
            pipes.push_back(make_pair(poz,tata[poz]));
        cost+=c[poz];
        viz[poz]=1;
        for(i=1;i<=n;++i)
            if((k[i]+k[poz])*distmanhattan(i,poz)<c[i])
            {
                c[i]=(k[i]+k[poz])*distmanhattan(i,poz);
                tata[i]=poz;
            }
        pas--;
    }
    printf("%lld\n%d\n",cost,powerstation.size());
    for(i=0;i<powerstation.size();++i)
        printf("%d ",powerstation[i]);
    printf("\n%d\n",pipes.size());
    for(i=0;i<pipes.size();++i)
        printf("%d %d\n",pipes[i].first,pipes[i].second);
    return 0;
}