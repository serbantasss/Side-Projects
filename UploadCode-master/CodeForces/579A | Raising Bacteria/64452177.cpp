#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("insule.in","r",stdin);
    //freopen("insule.out","w",stdout);
    int n,nr;
    scanf("%d",&n);
    nr=0;
    while(n)
    {
        if(n%2==1)
            nr++;
        n/=2;
    }
    printf("%d",nr);
    return 0;
}