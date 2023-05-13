//
//  main.cpp
//  delucru-geometrie-analitica
//
//  Created by Serban Bantas on 30/01/2020.
//  Copyright � 2020 Serban Bantas. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const double eps=1.e-14;///10^-14
const double INF=1.e9;///10^9
struct punct
{
    double x,y;
    int ind;
};
inline double dist(punct A,punct B)
{
    return sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
}
inline bool vertical(punct A,punct B)
{
    return fabs(B.x-A.x)<eps;
}
inline bool orizontala(punct A,punct B)
{
    return fabs(B.y-A.y)<eps;
}
inline double panta(punct A,punct B)
{
    if(vertical(A,B))
        return INF;
    else
        return (B.y-A.y)/(B.x-A.x);
}
vector<punct> st;
punct prim,p0;
bool cmpst(punct a, punct b)
{
    return atan2(a.y-prim.y, a.x-prim.x)<atan2(b.y-prim.y, b.x-prim.x);
}
int main(int argc, const char * argv[])
{
    freopen("mission.in","r",stdin);
    freopen("mission.out","w",stdout);
    int n,ind=-1;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        punct p;
        scanf("%lf %lf",&p.x,&p.y);
        if(i==0)
            p0=p;
        p.ind=i;
        prim.x+=p.x;
        prim.y+=p.y;
        st.push_back(p);
    }
    prim.x/=n;
    prim.y/=n;
    sort(st.begin(),st.end(),cmpst);
    for(int i=0;i<st.size();++i)
        if(st[i].x==p0.x && st[i].y==p0.y)
        {
            ind=i;
            printf("%d ",st[i].ind);
        }
        else
            if(ind!=-1)
                printf("%d ",st[i].ind);
    for(int i=0;i<ind;++i)
        printf("%d ",st[i].ind);
    return 0;
}