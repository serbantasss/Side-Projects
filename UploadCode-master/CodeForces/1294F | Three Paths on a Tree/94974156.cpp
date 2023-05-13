#include <bits/stdc++.h>
using namespace std;
vector<int>v[200005];
bool viz[200005];
int adc[200005],maxx,x,y,z;
pair<int,int> adcmax[200005];
void dfs1(int nod)
{
    viz[nod]=1;
    adcmax[nod]={0,nod};
    for(int i=0;i<v[nod].size();++i)
        if(!viz[v[nod][i]])
        {
            adc[v[nod][i]]=adc[nod]+1;
            dfs1(v[nod][i]);
            adcmax[nod]=max(adcmax[nod],{adcmax[v[nod][i]].first+1,adcmax[v[nod][i]].second});
        }
}
void dfs2(int nod,pair<int,int> t)
{
    viz[nod]=0;
    vector< pair<int,int> > v2;
    v2.push_back(t);
    for(int i=0;i<v[nod].size();++i)
        if(viz[v[nod][i]])
            v2.push_back({adcmax[v[nod][i]].first+1,adcmax[v[nod][i]].second});
    while(v2.size()<5)
        v2.push_back({0,0});
    sort(v2.begin(),v2.end());
    pair<int,int>a,b,c;
    a=v2[v2.size()-1];
    b=v2[v2.size()-2];
    c=v2[v2.size()-3];
    if(a.first+b.first+c.first>maxx)
        maxx=a.first+b.first+c.first,x=a.second,y=b.second,z=c.second;
    for(int i=0;i<v[nod].size();++i)
        if(viz[v[nod][i]])
            if(pair<int,int>{adcmax[v[nod][i]].first+1,adcmax[v[nod][i]].second}==a)
                dfs2(v[nod][i],{b.first+1,b.second});
            else
                dfs2(v[nod][i],{a.first+1,a.second});
}
int main()
{
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(1);
    x=y=z=maxx=0;
    dfs2(1,{0,1});
    if(z)
        printf("%d\n%d %d %d",maxx,x,y,z);
    else
    {
        for(int i=1;i<=n && !z;++i)
            if(i!=x && i!=y)
                z=i;
        printf("%d\n%d %d %d",maxx,x,y,z);
    }
    return 0;
}