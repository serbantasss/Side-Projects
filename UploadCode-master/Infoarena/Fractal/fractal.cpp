#include <cstdio>
using namespace std;
int fractal(int i,int j,int kp2)
{
    if(kp2==1)
        return 0;
    kp2/=2;
    if(i<=kp2 && j>kp2)
        return fractal(i,j-kp2,kp2)+kp2*kp2;
    if(i<=kp2 && j<=kp2)
        return fractal(j,i,kp2);
    if(i>kp2 && j<=kp2)
        return fractal(kp2+1-j,kp2+1-(i-kp2),kp2)+3*kp2*kp2;
    if(i>kp2 && j>kp2)
        return fractal(i-kp2,j-kp2,kp2)+2*kp2*kp2;
    return 0;
}
int main()
{
    freopen("fractal.in","r",stdin);
    freopen("fractal.out","w",stdout);
    int k,i,j,p2=1;
    scanf("%d%d%d",&k,&i,&j);
    for(int u=1;u<=k;++u)
        p2*=2;
    printf("%d",fractal(i,j,p2));
    return 0;
}