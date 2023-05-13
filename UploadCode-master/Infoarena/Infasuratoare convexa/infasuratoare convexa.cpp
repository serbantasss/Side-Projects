//
//  main.cpp
//  delucru-geometrie-analitica
//
//  Created by Serban Bantas on 30/01/2020.
//  Copyright © 2020 Serban Bantas. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const double pi=3.14159265358979323846264338327950288;
const double eps=1.e-14;///10^-14
const double INF=1.e9;///10^9
///INF poate lua valoare maxima 10^237
struct POINT
{
    double x,y;
};
struct DREPT
{
    POINT st,dr,st2,dr2;
};
struct CERC
{
    double r;
    POINT C;
};
struct ROMB
{
    POINT mij,st,dr,sus,jos;
    double r;
};
POINT mijloc(POINT A,POINT B)
{
    POINT M;
    M.x=(A.x+B.x)*0.5;
    M.y=(A.y+B.y)*0.5;
    return M;
}
DREPT axis_aligned_dreptunghi(DREPT D)
{
    D.dr2.x=D.dr.x;
    D.dr2.y=D.st.y;
    D.st2.x=D.st.x;
    D.st2.y=D.dr.y;
    return D;
}
double dist(POINT A,POINT B)
{
    return sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
}
bool same_point(POINT A,POINT B)
{
    return fabs(A.x-B.x)<eps and fabs(B.y-A.y)<eps;
}
bool vertical(POINT A,POINT B)
{
    return fabs(B.x-A.x)<eps;
}
bool orizontala(POINT A,POINT B)
{
    return fabs(B.y-A.y)<eps;
}
double panta(POINT A,POINT B)
{
    if(vertical(A,B))
        return INF;
    else
        return (B.y-A.y)/(B.x-A.x);
}
bool paralele(POINT A,POINT B,POINT C,POINT D)
{
    double p1,p2;
    p1=panta(A,B);
    p2=panta(C,D);
    return fabs(p1-p2)<eps;
}
bool perpendiculare(POINT A,POINT B,POINT C,POINT D)
{
    if((vertical(A,B) &&orizontala(C,D))||(vertical(C,D) &&orizontala(A,B)))
        return 1;
    double p1,p2;
    p1=panta(A,B);
    p2=panta(C,D);
    return fabs(p1*p2+1)<eps;
}
double aria_triunghi_heron(POINT A,POINT B,POINT C)
{
    double p;
    p=(dist(A,B)+dist(B,C)+dist(C,A))/2;
    return sqrt(p*(p-dist(A,B))*(p-dist(B,C))*(p-dist(C,A)));
}
double aria_triunghi_directionat(POINT A,POINT B,POINT C)
{
    double cp=(B.x-A.x)*(C.y-B.y)-(B.y-A.y)*(C.x-B.x);
    return cp*0.5;
}
double semn(POINT A,POINT B,POINT C)
{
    if(aria_triunghi_directionat( A, B, C)<=0.0)
        return -1;
    return 1;
}
double aria_dreptunghi(DREPT D)
{
    return dist(D.st,D.dr2)*dist(D.st,D.st2);
}
bool punct_interior_triunghi(POINT A,POINT B,POINT C,POINT P)
{
    double s=aria_triunghi_directionat(A,B,P)+aria_triunghi_directionat(B,P,C)+aria_triunghi_directionat(A,P,C);
    return fabs(s-aria_triunghi_directionat(A,B,C))<eps;
}
bool punct_interior_dreptunghi(DREPT D,POINT P)
{
    return (P.x-D.st.x>=eps && D.dr.x-P.x>=eps && D.dr.y-P.y>=eps && P.y-D.st.y>=eps)||(P.x>=D.st.x && D.dr.x>=P.x && D.dr.y>=P.y && P.y>=D.st.y);
}
bool punct_interior_romb(ROMB R,POINT P)
{
    return punct_interior_triunghi(R.sus, R.st, R.dr, P) || punct_interior_triunghi(R.jos, R.st, R.dr, P);
}
bool punct_interior_cerc(CERC C,POINT P)
{
    return ((P.y-C.C.y)*(P.y-C.C.y)+(P.x-C.C.x)*(P.x-C.C.x)-(C.r)*(C.r))<=-eps;
}
double aria_intersectie_dreptunghi(DREPT D1,DREPT D2)
{
    POINT st,dr;
    DREPT D;
    st.x=max(min(D1.st.x,D1.dr.x),min(D2.st.x,D2.dr.x));
    dr.x=min(max(D1.st.x,D1.dr.x),max(D2.st.x,D2.dr.x));
    dr.y=min(max(D1.st.y,D1.dr.y),max(D2.st.y,D2.dr.y));
    st.y=max(min(D1.st.y,D1.dr.y),min(D2.st.y,D2.dr.y));
    D.dr=dr;
    D.st=st;
    D=axis_aligned_dreptunghi(D);
    if(dr.x<=st.x || dr.y<=st.y)
        return 0.0;
    return aria_dreptunghi(D);
}
long long _gcd(long long a, long long b)
{
    if (b==0)
        return a;
    return _gcd(b,a%b);
}
long long gcd(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
double gcd(double a,double b)
{
    a=fmod(a,b);
    if(fabs(a)<eps)
        return b;
    else
        if(fabs(b)<eps)
            return a;
        else
            return gcd(b,a);
}
POINT st;
vector<POINT> v;
POINT stiva[120005];
bool cmp_panta(POINT A,POINT B)
{
    if(fabs(panta(st,A)-panta(st,B))<eps && fabs(panta(st,A)-INF)<eps)
        return A.y<B.y;
    return panta(st,A)<panta(st,B);
}
int main(int argc, const char * argv[])
{
    freopen("infasuratoare.in","r",stdin);
    freopen("infasuratoare.out","w",stdout);
    int n,i,sttop=0;
    POINT P;
    scanf("%d",&n);
    st.x=INF;
    st.y=INF;
    for(i=1;i<=n;++i)
    {
        scanf("%lf%lf",&P.x,&P.y);
        v.push_back(P);
        if(st.x-P.x>eps)
            st=P;
        else
            if(fabs(P.x-st.x)<eps && st.y-P.y>eps)
                st=P;
    }
    for(i=0;i<n;++i)
        if(vertical(st,v[i]) && orizontala(st, v[i]))
        {
            v.erase(v.begin()+i);
            n--;
            break;
        }
    sort(v.begin(),v.end(),cmp_panta);
    stiva[++sttop]=st;
    stiva[++sttop]=v[0];
    stiva[++sttop]=v[1];
    for(i=2;i<n;++i)
    {
        while(sttop>=2 && semn(stiva[sttop-2], stiva[sttop-1],  stiva[sttop])!=semn(stiva[sttop-1], stiva[sttop], v[i]))
            sttop--;
        stiva[++sttop]=v[i];
    }
    printf("%d\n",sttop);
    for(i=1;i<=sttop;++i)
        printf("%lf %lf\n",stiva[i].x,stiva[i].y);
    return 0;
}