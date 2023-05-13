#include <cstdio>
 
using namespace std;
 
int main()
{   freopen("operatii.in","r",stdin);
    freopen("operatii.out","w",stdout);
    long long int n,last=0,sol=0,cur=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&cur);
        if(cur>last)
        {
            sol+=cur-last;
        }
        last=cur;
    }
    printf("%lld",sol);
    return 0;
}