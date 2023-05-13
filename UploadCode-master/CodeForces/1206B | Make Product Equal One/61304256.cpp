#include <cstdio>
 
using namespace std;
 
int main()
{
    long long int n,i,nminus,nplus,n0,x,optot=0;
    nminus=nplus=n0=0;
    scanf("%lld",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%lld",&x);
        if(x<-1)
            optot+=(-1)*x-1,nminus++;
        if(x==-1)
            nminus++;
        if(x==0)
            n0++;
        if(x==1)
            nplus++;
        if(x>1)
            optot+=x-1,nplus++;
    }
    if(nminus%2==0)
        optot+=n0;
    else
    {
        if(n0>0)
            optot+=n0;
        else
            optot+=2;
    }
    printf("%lld",optot);
    return 0;
}