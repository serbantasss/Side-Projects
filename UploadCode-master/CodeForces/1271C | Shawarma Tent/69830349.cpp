#include <bits/stdc++.h>
#define M_PI 3.14159265359
using namespace std;
const double eps=1.e-6;
struct point
{
    double x,y;
};
double lung(point A,point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double aria(point A,point B,point C)
{
    double cp=(B.x-A.x)*(C.y-B.y)-(B.y-A.y)*(C.x-B.x);
    return fabs(cp)*0.5;
}
bool interior(point A,point B,point C,point P)
{
    double s;
    s=aria(P,A,B)+aria(P,B,C)+aria(P,C,A);
    if(fabs(s-aria(A,B,C))<eps)
        return 1;
    else
        return 0;
}
int main()
{
    //    freopen("cabana.in","r",stdin);
    //    freopen("cabana.out","w",stdout);
    int n,i,sus=0,jos=0,dreapta=0,stanga=0,sx,sy,x,y,ma;
    scanf("%d%d%d",&n,&sx,&sy);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&x,&y);
        if(x>sx)
            sus++;
        if(x<sx)
            jos++;
        if(y>sy)
            dreapta++;
        if(y<sy)
            stanga++;
    }
    ma=max(stanga,max(dreapta,max(sus,jos)));
    printf("%d\n",ma);
    if(ma==stanga)
        printf("%d %d",sx,sy-1);
    else if(ma==dreapta)
        printf("%d %d",sx,sy+1);
    else if(ma==sus)
        printf("%d %d",sx+1,sy);
    else if(ma==jos)
        printf("%d %d",sx-1,sy);
    return 0;
}