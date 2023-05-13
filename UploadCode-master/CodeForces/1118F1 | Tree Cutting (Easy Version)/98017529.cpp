#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int NMAX=300005;
int cul[NMAX],tata[NMAX];
pair<int,int> pule[NMAX];
pair<int,int> nr[NMAX];
vector<int> adc[NMAX];
void dfs(int nod,int tt)
{
    if(cul[nod]==1)
        nr[nod].x++;
    if(cul[nod]==2)
        nr[nod].y++;
    for(int i=0;i<adc[nod].size();++i)
        if(adc[nod][i]!=tt)
        {
            tata[adc[nod][i]]=nod;
            dfs(adc[nod][i],nod);
            nr[nod].x+=nr[adc[nod][i]].x;
            nr[nod].y+=nr[adc[nod][i]].y;
        }
}
int main()
{
    int n,n1=0,n2=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&cul[i]);
        if(cul[i]==1)
            n1++;
        if(cul[i]==2)
            n2++;
    }
    for(int i=1;i<n;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adc[a].push_back(b),adc[b].push_back(a);
        pule[i].x=a,pule[i].y=b;
    }
    dfs(1,1);
    for(int i=1;i<n;++i)
    {
        if(tata[pule[i].y]!=pule[i].x)
            swap(pule[i].x,pule[i].y);
        if(nr[pule[i].y].y==n2 && nr[pule[i].y].x==0)
            ans++;
        else
            if(nr[pule[i].y].x==n1 && nr[pule[i].y].y==0)
                ans++;
    }
    printf("%d",ans);
    return 0;
}