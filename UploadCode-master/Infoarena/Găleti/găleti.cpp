#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int q[100005],v[100005];
int n;
bool verif(const long long &x)
{
    long long rx=0;
    for(int i=1; i<=n ; ++i)
    {
        if(1LL*v[q[i]]>rx+x)
            return 0;
        rx=rx+x-1LL*v[q[i]];
    }
    return 1;
}
bool cmp(const int &a,const int &b)
{
    return v[a]<v[b];
}
int cautarebinara(int st,int dr)
{
    int mid,ans=1000000000;
    while(st<=dr)
    {
        mid=(st+dr)>>1;
        if(verif(1LL*mid))
        {
            ans=mid;
            dr=mid-1;
        }
        else
            st=mid+1;
    }
    return ans;
}
int main()
{
    freopen("galeti.in","r",stdin);
    freopen("galeti.out","w",stdout);
    int i,j,x,st,dr,mid,ans,ma=0;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
        scanf("%d",&q[i]);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&v[i]);
    }
    printf("%d\n",cautarebinara(1,1000000000));
    sort(q+1,q+n+1,cmp);
    for(i=1;i<=n;++i)
        printf("%d ",q[i]);
    printf("\n%d\n",cautarebinara(1,1000000000));
    return 0;
}