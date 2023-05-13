#include <cstdio>
#include <algorithm>
using namespace std;
const int nmax=200005;
int v[nmax];
long long st[nmax],dr[nmax];
int stiva[nmax];
inline long long max(long long a,long long b)
{
    if(a<b)
        return b;
    return a;
}
int main()
{
    freopen("strabunica.in", "r", stdin);
    freopen("strabunica.out", "w", stdout);
    int n,top=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;++i)
    {
        while(v[i]<=v[stiva[top]] && top>0)
            top--;
        st[i]=stiva[top];
        stiva[++top]=i;
    }
    top=0;
    stiva[top]=n+1;
    for(int i=n;i>=1;--i)
    {
        while(v[i]<=v[stiva[top]] && top>0)
            top--;
        dr[i]=stiva[top];
        stiva[++top]=i;
    }
    long long ans=-1;
    for(int i=1;i<=n;++i)
        ans=max(ans,v[i]*(dr[i]-st[i]-1));
    printf("%lld",ans);
    return 0;
}