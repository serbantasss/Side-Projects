#include <cstdio>
#include <algorithm>
using namespace std;
int mat[1005][1005];
int resturi[1005];
int main()
{
    //freopen("partitie1.in","r",stdin);
    ///freopen("partitie1.out","w",stdout);
    int b,a,k,paritate=0,par,i;
    scanf("%d%d",&b,&k);
    for(i=1; i<k; ++i)
    {
        scanf("%d",&a);
        par=(a%2)*(b%2);
        if(paritate==1)
        {
            if(par==1)
                paritate=0;
        }
        else
        {
            if(par==1)
                paritate=1;
        }
    }
    scanf("%d",&a);
    par=a%2;
    if(paritate==1)
    {
        if(par==1)
            paritate=0;
    }
    else
    {
        if(par==1)
            paritate=1;
    }
    if(paritate==1)
        printf("odd");
    else
        printf("even");
    return 0;
}