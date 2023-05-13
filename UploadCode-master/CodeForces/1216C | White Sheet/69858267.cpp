#include <bits/stdc++.h>
using namespace std;
const double eps=1.e-14;///10^-14
const double INF=1.e9;///10^9
///INF poate lua valoare maxima 10^237
struct POINT
{
    double x,y;
};
struct DREPT
{
    POINT st,dr;
    POINT st2,dr2;
};
struct CERC
{
    double r;
    POINT C;
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
double aria_triunghi(POINT A,POINT B,POINT C)
{
    double p;
    p=(dist(A,B)+dist(B,C)+dist(C,A))/2;
    return sqrt(p*(p-dist(A,B))*(p-dist(B,C))*(p-dist(C,A)));
}
double aria_dreptunghi(DREPT D)
{
    return dist(D.st,D.dr2)*dist(D.st,D.st2);
}
bool punct_interior_triunghi(POINT A,POINT B,POINT C,POINT P)
{
    double s=aria_triunghi(A,B,P)+aria_triunghi(B,P,C)+aria_triunghi(A,P,C);
    return fabs(s-aria_triunghi(A,B,C))<eps;
}
bool punct_interior_dreptunghi(DREPT D,POINT P)
{
    return P.x-D.st.x>=eps && D.dr.x-P.x>=eps && P.y-D.dr.y>=eps && D.st.y-P.y>=eps;
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
DREPT boiii(DREPT D1,DREPT D2)
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
        {
            D.st.x=D.st.y=D.dr.x=D.dr.y=0;
            D=axis_aligned_dreptunghi(D);
        }
    return D;
}
int main()
{
    DREPT a,n1,n2;
    scanf("%lf%lf%lf%lf",&a.st.x,&a.st.y,&a.dr.x,&a.dr.y);
    a=axis_aligned_dreptunghi(a);
    scanf("%lf%lf%lf%lf",&n1.st.x,&n1.st.y,&n1.dr.x,&n1.dr.y);
    n1=axis_aligned_dreptunghi(n1);
    scanf("%lf%lf%lf%lf",&n2.st.x,&n2.st.y,&n2.dr.x,&n2.dr.y);
    n2=axis_aligned_dreptunghi(n2);
    DREPT inter1=boiii(a, n1),inter2=boiii(a, n2);
    if(aria_intersectie_dreptunghi(a, n1)+aria_intersectie_dreptunghi(a, n2)-aria_intersectie_dreptunghi(inter1, inter2)<aria_dreptunghi(a))
        printf("YES");
    else
        printf("NO");
    return 0;
}