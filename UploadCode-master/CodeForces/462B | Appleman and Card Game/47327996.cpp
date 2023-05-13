#include <cstdio>
#include <algorithm>
 
using namespace std;
long long  f[100];
int main()
{
    long long n,k,i,j;
    long long ans=0;
    scanf("%lld%lld",&n,&k);
    for(i=1;i<=n;++i)
    {
        char ch;
        scanf("\n%c",&ch);
        f[ch-'A']++;
    }
    sort(f,f+26);
    for(i=25;i>=0 && k;--i)
    {
        if(k>=f[i])
            k-=f[i],ans=ans+f[i]*f[i];
        else
        {
            ans=ans+k*k;
            k=0;
        }
    }
    printf("%lld",ans);
    return 0;
}