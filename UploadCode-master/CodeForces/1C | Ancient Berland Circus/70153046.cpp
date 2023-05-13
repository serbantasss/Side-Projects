#include<bits/stdc++.h>
using namespace std;
double eps=1E-2;
const double pi=3.14159265358979323846264338327950288;
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
int main()
{
    double xa,xb,xc,ya,yb,yc;
    scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc);
    double c2=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
    double a2=(xc-xb)*(xc-xb)+(yc-yb)*(yc-yb);
    double b2=(xc-xa)*(xc-xa)+(yc-ya)*(yc-ya);
    double a=sqrt(a2),b=sqrt(b2),c=sqrt(c2);
    double l=(a+b+c)/2;
    double R2 = a2*b2*c2/16/(l*(l-a)*(l-b)*(l-c));
    a=acos(1-a2/R2/2);
    b=acos(1-b2/R2/2);
    c=2*pi-a-b;
    double X=gcd(a,gcd(b,c));
    double N = 2*pi/X;
    printf("%.8lf\n",R2*sin(X)/2*N);
    return 0;
}