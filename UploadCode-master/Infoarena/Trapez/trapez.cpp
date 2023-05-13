#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const double  eps=1.e-14;
const double  INF=2.e9;
struct point
{
    double x,y;
};
double dist(point A,point B)
{
    return sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
}
bool vertical(point A,point B)
{
    return (fabs(A.x-B.x)<eps);
}
bool orizontala(point A,point B)
{
    return (fabs(A.y-B.y)<eps);
}
double panta(point A,point B)
{
    if(vertical(A,B)) return INF;
    return (A.y-B.y)/(A.x-B.x);
}
vector<double>  v;
vector<point> pct;
int main()
{
    freopen("trapez.in","r",stdin);
    freopen("trapez.out","w",stdout);
    int x,y,fss,s=0,n,i,j;
    double m;
    point c;
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d %d",&x,&y);
        c.x=x;
        c.y=y;
        pct.push_back(c);
    }
    for(i=0;i<pct.size();++i)
        for(j=i+1;j<pct.size();++j)
            v.push_back(panta(pct[i],pct[j]));
    sort(v.begin(),v.end());
    m = v[0];
    fss = 1;
    for(i = 1;i < v.size();i++)
    {
        if(v[i] > m)
        {
            s += (fss * (fss - 1)) / 2;
            m = v[i];
            fss = 1;
        }
        else if(v[i] == m)
            fss++;
    }
    s += (fss * (fss - 1)) / 2;
    printf("%d",s);
    return 0;
    return 0;
}