#include <bits/stdc++.h>
#define INF 1LL<<40
typedef long long LL;
using namespace std;
int v[10005];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,i,j,m,x,sumtot=0,ans=0,cnt=0;
    scanf("%d",&n);
     for(;n;--n)
    {
        scanf("%d",&m);
        for(i=0;i<m;++i)
        {
            scanf("%d",&x);
            if(i<m/2)
                ans+=x;
            sumtot+=x;
            if(m%2==1 && i==m/2)
                v[++cnt]=x;
        }
    }
    sort(v+1,v+cnt+1,cmp);
    for(i=1;i<=cnt;i+=2)
        ans+=v[i];
    printf("%d %d",ans,sumtot-ans);
    return 0;
}