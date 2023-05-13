#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    long long a,b,ans=0,bit;
    scanf("%lld%lld",&a,&b);
    bit=63;
    while(bit>=0)
    {
        if( ((1LL<<bit)&a)  != ((1LL<<bit)&b ))
            while(bit>=0)
                ans=ans+(1LL<<(bit--));
        bit--;
    }
    printf("%lld",ans);
    return 0;
}