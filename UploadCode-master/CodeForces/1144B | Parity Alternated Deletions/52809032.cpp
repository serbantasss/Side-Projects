#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int par[2005];
int impar[2005];
int main()
{
    int n,i,j,np=0,ni=0,mi,x;
    scanf("%d\n",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        if(x%2==0)
            par[++np]=x;
        else
            impar[++ni]=x;
    }
    sort(par+1,par+np+1);
    sort(impar+1,impar+ni+1);
    long long s=0;
    if(ni==np || ni+1==np || np+1==ni)
    {
        printf("0");
    }
    else
    {
        if(ni<np)
            for(i=1;i<=np-ni-1;++i)
                s+=par[i];
        else
            for(i=1;i<=ni-np-1;++i)
                s+=impar[i];
        printf("%lld",s);
    }
    return 0;
}