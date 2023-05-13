#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,d;
    scanf("%lld",&n);
    for(d=2;d*d<=n;++d)
        while(n%(d*d)==0)
            n/=d;
    printf("%lld",n);
    return 0;
}