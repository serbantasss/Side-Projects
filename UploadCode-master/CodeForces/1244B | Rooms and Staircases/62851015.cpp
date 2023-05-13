#include <bits/stdc++.h>
using namespace std;
int v[1005];
int main()
{
    //freopen("homm.in","r",stdin);
    //freopen("homm.out","w",stdout);
    int t,n,i,prima = 0,ultima = 0,ok;
    scanf("%d",&t);
    for(;t;t--)
    {
        scanf("%d",&n);
        ok=1;
        for(i=1;i<=n;++i)
        {
            scanf("%1d",&v[i]);
            if(v[i]==1)
                ultima=i;
            if(v[i]==1 && ok)
            {
                ok=0;
                prima=i;
            }
        }
        int d1=n-prima+1,d2=ultima;
        d1=d1*2;
        d2=d2*2;
        if(ok==1)
            printf("%d\n",n);
        else
            printf("%d\n",max(d1,d2));
    }
    return 0;
}