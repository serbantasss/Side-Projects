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
    return fabs(cp)*0.5;
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
int main(int argc, const char * argv[])
{
    double l1,l2,l3;
    scanf("%lf%lf%lf",&l1,&l2,&l3);
    double v1=l1*l1*l1*sqrt(2.0)/12.0;
    double v2=l2*l2*l2*sqrt(2.0)/6.0;
    double r=l3/(2.0*sin(pi/5));
    double A=l3*l3*0.25*sqrt(5.0*(5.0+2.0*sqrt(5.0))),h=sqrt(l3*l3-r*r);
    double v3=h*A/3.0;
    double v11=(sqrt(2)*(l1*l1*l1))/12;
    double v22=(sqrt(2)*(l2*l2*l2))/6;
    double v33=((5+sqrt(5))*(l3*l3*l3))/24;
    printf("%.10lf",v1+v2+v3);
    return 0;
}