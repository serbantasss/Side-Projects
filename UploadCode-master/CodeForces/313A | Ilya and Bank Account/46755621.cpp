#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int v[100];
int main()
{
    int n,i,cn,n1=0,n2=0,nr=0;
    scanf("%d",&n);
    cn=n;
    do
    {
        v[++nr]=cn%10;
        cn/=10;
    }while(cn);
    int pw=10;
    n1=v[1];
    for(i=3;i<=nr;++i)
    {
        n1=n1+pw*v[i];
        pw*=10;
    }
    pw=10;
    n2=v[2];
    for(i=3;i<=nr;++i)
    {
        n2=n2+pw*v[i];
        pw*=10;
    }
    printf("%d",max(n1,max(n,n2)));
    return 0;
}