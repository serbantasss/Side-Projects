#include <cstdio>
using namespace std;
long long int sp[200005],si[200005];
int main()
{
    // freopen("cmmmc.in","r",stdin);
    // freopen("cmmmc.out","w",stdout);
    long long int n,i,j,k=0,poz,x,s1,s2;
    scanf("%lld",&n);
    scanf("%lld",&si[1]);
    for(i=2; i<=n; ++i)
    {
        scanf("%lld",&x);
        if(i%2==1)
            si[i]=si[i-2]+x;
        else
            sp[i]=sp[i-2]+x;
    }
    ///elimin 1
    if(n%2==0)
    {
        s1=sp[n];
        s2=si[n-1]-si[1];
        if(s1==s2)
            k++;
    }
    else
    {
        s1=sp[n-1];
        s2=si[n]-si[1];
        if(s1==s2)
            k++;
    }
    for(poz=2; poz<=n; ++poz)
        if(poz%2==0)
        {
            s1=sp[poz-2];
            s2=si[poz-1];
            if(n%2==0)
            {
                s1+=si[n-1]-si[poz-1];
                s2+=sp[n]-sp[poz];
                if(s1==s2)
                    k++;
            }
            else
            {
                s1+=si[n]-si[poz-1];
                s2+=sp[n-1]-sp[poz];
                if(s1==s2)
                    k++;
            }
        }
        else
        {
            s1=sp[poz-1];
            s2=si[poz-2];
            if(n%2==0)
            {
                s1+=si[n-1]-si[poz];
                s2+=sp[n]-sp[poz-1];
                if(s1==s2)
                    k++;
            }
            else
            {
                s1+=si[n]-si[poz];
                s2+=sp[n-1]-sp[poz-1];
                if(s1==s2)
                    k++;
            }
        }
    printf("%lld",k);
    return 0;
}