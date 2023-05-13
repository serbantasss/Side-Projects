#include <bits/stdc++.h>
using namespace std;
int v[10005],poz[10005];
int main()
{
//    freopen("cabana.in","r",stdin);
//    freopen("cabana.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,p,x;
        bool ok;
        scanf("%d%d",&n,&p);
        for(int i=1;i<=n;++i)
            scanf("%d",&v[i]),poz[i]=0;
        for(int i=1;i<=p;++i)
        {
            scanf("%d",&x);
            poz[x]=1;
        }
        do
        {
            ok=0;
            for(int i=1;i<n;++i)
                if(poz[i] && v[i]>v[i+1])
                    swap(v[i],v[i+1]),ok=1;
        }while(ok);
        ok=1;
        for(int i=1;i<n && ok;++i)
            if(v[i]>v[i+1])
                ok=0;
        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
        
    }
    return 0;
}