#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,p,d,w,a,b=0,c;
    scanf("%lld%lld%lld%lld",&n,&p,&d,&w);
    while(b<d && (p-w*b)%d)
        b++;
    if(b==d)
    {
        printf("-1");
        return 0;
    }
    a=(p-w*b)/d;
    c=n-a-b;
    if(a>=0 && c>=0)
        printf("%lld %lld %lld",a,b,c);
    else
        printf("-1");
    return 0;
}