#include <bits/stdc++.h>
using namespace std;
struct intt
{
    int s,ab,ind;
};
intt v[2][30005];
long long sa,sb;
int viz[30005];
bool cmp(intt x,intt y)
{
    if(x.s==y.s)
        if(x.ab==y.ab)
            return x.ind<y.ind;
        else
            return x.ab<y.ab;
    return x.s<y.s;
}
int main()
{
    freopen("gramezi.in","r",stdin);
    freopen("gramezi.out","w",stdout);
    int n,i,a,b,ma=0,x;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%d%d",&a,&b);
        v[0][i].s=a+b;
        v[0][i].ab=b;
        v[0][i].ind=i;
        v[1][i].s=a+b;
        v[1][i].ab=a;
        v[1][i].ind=i;
    }
    sort(v[0]+1,v[0]+n+1,cmp);
    sort(v[1]+1,v[1]+n+1,cmp);
    int ind1,ind2;
    ind1=ind2=n;
    for(i=1; i<=n; ++i)
        if(i%2==1)
        {
            for(; viz[v[1][ind1].ind]; ind1--);
            sa=sa+v[1][ind1].ab;
            viz[v[1][ind1].ind]=1;
        }
        else
        {
            for(; viz[v[0][ind2].ind]; ind2--);
            sb=sb+v[0][ind2].ab;
            viz[v[0][ind2].ind]=1;
        }
    printf("%lld %lld",sa,sb);
    return 0;
}