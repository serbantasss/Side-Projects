#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int v[1000005],q[1000005];
int main()
{
    freopen("cufar.in","r",stdin);
    freopen("cufar.out","w",stdout);
    int n,i,j,m,k,p;
    scanf("%d%d",&p,&n);
    long long int s=0,x;
    for(i=1; i<=n; ++i)
    {
        scanf("%d%d",&x,&k);
        v[x]=k;
    }
    for(i=2; i<=1000000; ++i)
        if(q[i]==0)
            for(j=i; j<=1000000; j+=i)
            {
                q[j]++;
                if(q[j]==v[j])
                    s+=i;
            }
    printf("%lld",s);
    return 0;
}