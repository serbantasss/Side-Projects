#include <cstdio>
#include <vector>
using namespace std;
vector<long long> dif;
long long v[1000005],per[1000005];
int main()
{
    freopen("perioada01.in","r",stdin);
    freopen("perioada01.out","w",stdout);
    long long n,p,ok;
    scanf("%lld%lld",&n,&p);
    dif.push_back(0);
    for(int i=1;i<=p;++i)
    {
        scanf("%lld",&v[i]);
        if(i>1)
            dif.push_back(v[i]-v[i-1]);
    }
    dif.push_back(n-v[p]+v[1]);
    per[1]=0;
    for(int i=2,k=0;i<=p;++i)
    {
        while(dif[i]!=dif[k+1] && k>=1)
            k=per[k];
        if(dif[i]==dif[k+1])
            k++;
        per[i]=k;
    }
    if(p%(p-per[p])!=0 && per[p]!=0)
        printf("-1");
    else
    {
        long long ans=0;
        for(int i=1;i<=p-per[p];++i)
            ans+=dif[i];
        printf("%lld",ans);
    }
    return 0;
}