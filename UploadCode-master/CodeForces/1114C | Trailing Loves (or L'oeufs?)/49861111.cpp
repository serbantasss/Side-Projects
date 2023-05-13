#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    long long int N,B,i,j,p,c,noz,k;
    scanf("%lld%lld",&N,&B);
    noz=N;
    j=B;
    for (i=2; i<=sqrtl(B); i++)
    {
        if (j%i==0)
        {
            p=0;
            while (j%i==0)
            {
                p++;
                j/=i;
            }
            c=0;
            k=N;
            while (k/i>0)
            {
                c+=k/i;
                k/=i;
            }
            noz=min(noz,c/p);
        }
    }
    if(j>1)
    {
        i=j;
        if (j%i==0)
        {
            p=0;
            while (j%i==0)
            {
                p++;
                j/=i;
            }
            c=0;
            k=N;
            while (k/i>0)
            {
                c+=k/i;
                k/=i;
            }
            noz=min(noz,c/p);
        }
    }
    printf("%lld\n",noz);
    return 0;
}