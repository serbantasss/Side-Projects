#include <bits/stdc++.h>
#define INF 1LL<<40
typedef long long LL;
using namespace std;
int main()
{
 int n,i,x,cm;
 scanf("%d%d",&n,&cm);
 for(i=2;i<=n;++i)
    {
        scanf("%d",&x);
        cm=__gcd(cm,x);
    }
    printf("%d",cm*n);
 
 return 0;
}