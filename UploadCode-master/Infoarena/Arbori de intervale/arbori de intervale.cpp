#include <cstdio>
#include <algorithm>
using namespace std;
int v[100005],aint[400020];
int n,m,sol;
void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        aint[nod]=v[st];
    }
    else
    {
        int med=(st+dr)/2;
        build(2*nod,st,med);
        build(2*nod+1,med+1,dr);
        aint[nod]=max(aint[2*nod],aint[2*nod+1]);
    }
}
void update(int nod,int st,int dr,int pozv,int new_val)
{
    if(st==dr)
    {
        aint[nod]=new_val;
    }
    else
    {
        int med=(st+dr)/2;
        if(pozv<=med)
            update(2*nod,st,med,pozv,new_val);
        if(pozv>=med+1)
            update(2*nod+1,med+1,dr,pozv,new_val);
        aint[nod]=max(aint[2*nod],aint[2*nod+1]);
    }
}
void query(int nod,int st,int dr,int a,int b)
{
    if(a<=st && dr<=b)
    {
        sol=max(sol,aint[nod]);
    }
    else
    {
        int med=(st+dr)/2;
        if(a<=med)
            query(2*nod,st,med,a,b);
        if(b>=med+1)
            query(2*nod+1,med+1,dr,a,b);
    }
}
int main()
{
    freopen("arbint.in","r",stdin);
    freopen("arbint.out","w",stdout);
    int i,j,x,y,z;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
    }
    build(1,1,n);
    for(i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(x==0)
        {
            sol=0;
            query(1,1,n,y,z);
            printf("%d\n",sol);
        }
        else
        {
            update(1,1,n,y,z);
        }
    }
    return 0;
}