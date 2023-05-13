#include <bits/stdc++.h>
using namespace std;
int conc(int a,int b)
{
    int cb=a;
    do
    {
        a*=10;
        cb/=10;
    }while(cb);
    a+=b;
    return a;
}
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long A,B,ans,nrcif=0;
        scanf("%lld%lld",&A,&B);
        B++;
        while(B>0)
            B/=10,nrcif++;
        printf("%lld\n",(nrcif-1)*A);
    }
    return 0;
}