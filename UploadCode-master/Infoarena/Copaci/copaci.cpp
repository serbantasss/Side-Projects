//
//  main.cpp
//  delucru-geometrie-analitica
//
//  Created by Serban Bantas on 30/01/2020.
//  Copyright � 2020 Serban Bantas. All rights reserved.
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
struct POLIGON
{
    POINT p[100005];
    int n;
};
POINT mijloc(POINT A,POINT B)
{
    POINT M;
    M.x=(A.x+B.x)*0.5;
    M.y=(A.y+B.y)*0.5;
    return M;
}
inline DREPT axis_aligned_dreptunghi(DREPT D)
{
    D.dr2.x=D.dr.x;
    D.dr2.y=D.st.y;
    D.st2.x=D.st.x;
    D.st2.y=D.dr.y;
    return D;
}
inline double dist(POINT A,POINT B)
{
    return sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
}
inline bool same_point(POINT A,POINT B)
{
    return fabs(A.x-B.x)<eps and fabs(B.y-A.y)<eps;
}
inline bool vertical(POINT A,POINT B)
{
    return fabs(B.x-A.x)<eps;
}
inline bool orizontala(POINT A,POINT B)
{
    return fabs(B.y-A.y)<eps;
}
inline double panta(POINT A,POINT B)
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
double aria_dreptunghi(DREPT D)
{
    return dist(D.st,D.dr2)*dist(D.st,D.st2);
}
double aria_poligon(POLIGON P)
{
    double a=0.0;
    int i,j=P.n-1;
    for(i=0;i<P.n;++i)
    {
        a+=(P.p[j].x+P.p[i].x)*(P.p[j].y-P.p[i].y);
        j=i;
    }
    return fabs(a)/2.0;
}
double semn(POINT A,POINT B,POINT C)
{
    if(aria_triunghi_directionat( A, B, C)<=0.0)
        return -1;
    return 1;
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
bool punct_interior_segment(POINT A,POINT B,POINT P)
{
    if(aria_triunghi_directionat(A, B, P)==0)
    {
        if(A.x>B.x)
            if(A.y>B.y)
                return A.x>=P.x && P.x>=B.x && A.y>=P.y && P.y>=B.y;
            else
                return A.x>=P.x && P.x>=B.x && A.y<=P.y && P.y<=B.y;
        else
            if(A.y<B.y)
                return A.x<=P.x && P.x<=B.x && A.y<=P.y && P.y<=B.y;
            else
                return A.x<=P.x && P.x<=B.x && A.y>=P.y && P.y>=B.y;
    }
    return 0;
}
bool punct_interior_poligon(POINT p,POLIGON P)
{
    int i,j,c=0;
    for (i = 0, j = P.n-1; i < P.n; j = i++)
    {
        if ( ((P.p[i].y>p.y) != (P.p[j].y>p.y)) && (p.x < (P.p[j].x-P.p[i].x) * (p.y-P.p[i].y) / (P.p[j].y-P.p[i].y) + P.p[i].x) )
            c = !c;
    }
    if(c==0)
    {
        for(i=0;i<P.n;++i)
            if(i==P.n-1)
            {
                if(punct_interior_segment(P.p[i], P.p[0], p))
                    return 1;
            }
        else
            if(punct_interior_segment(P.p[i], P.p[i+1], p))
                return 1;
    }
    return c;
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
double fgcd(double a,double b)
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
inline long long count_puncte_segment(POINT A,POINT B)
{
    if(vertical(A, B))
        return round(fabs(A.y-B.y)-1);
    if(orizontala(A, B))
        return round(fabs(A.x-B.x)-1);
    return gcd(round(fabs(A.x-B.x)), round(fabs(A.y-B.y)))-1;
}
long long count_puncte_poligon(POLIGON P)
{
    int i,j=P.n-1;
    long long pct=P.n,area=round(aria_poligon(P));
    for(i=0;i<P.n;++i)
    {
        pct+=count_puncte_segment(P.p[j], P.p[i]);
        j=i;
    }
    return (2*area-pct+2)/2;
}
int main(int argc, const char * argv[])
{
    freopen("copaci.in","r",stdin);
    freopen("copaci.out","w",stdout);
    POLIGON P;
    scanf("%d",&P.n);
    for(int i=0;i<P.n;++i)
        scanf("%lf %lf",&P.p[i].x,&P.p[i].y);
    printf("%lld\n",count_puncte_poligon(P));
    return 0;
}