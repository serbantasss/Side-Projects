/*#include <bits/stdc++.h>
using namespace std;
int v[2005],stiva[3005];
int n,m;
int main()
{
    //freopen("masterpiece001.in","r",stdin);
    //freopen("masterpiece001.out","w",stdout);
    int i,j,c,s,smax=0;
    long long st=0,dr=LLONG_MAX,mid,out,sumall;
    scanf("%d%d",&c,&n);
    m=n*(n+1)/2;
    for(i=1; i<=n; ++i)
    {
        s=0;
        for(j=1; j<=i; ++j)
        {
            scanf("%d",&v[i*(i-1)/2+j]);
            s+=v[i*(i-1)/2+j];
        }
        sumall+=s;
        if(s>smax)
            smax=s,out=i;
    }
    if(c==1)
    {
        printf("%lld",out);
        return 0;
    }
    int ph=0,niv=1,tot=0;
    while(ph<m)
    {

    }
    printf("%lld %lld",tot,tot-sumall);
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
long long v,n,M[55][55],T[55][55];
bool ok(long long k)
{
    memset(T,0,sizeof T);
    T[1][1]=k;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=i; ++j)
        {
            if(T[i][j]<M[i][j])
                return 0;
            T[i][j]-=M[i][j];
            T[i+1][j]+=T[i][j]/2LL;
            T[i+1][j+1]=T[i][j]/2LL;
            if(T[i][j]&1)
                T[i+1][j]++;
        }
    return 1;
}
int main()
{
    freopen("pic.in","r",stdin);
    freopen("pic.out","w",stdout);
    long long step=0,sol_2=0,sol_1=0,sumi=0,s_tot=0;
    scanf("%lld%lld",&v,&n);
    for(int i=1; i<=n; ++i)
    {
        int sum=0;
        for(int j=1; j<=i; ++j)
        {
            scanf("%d",&M[i][j]);
            sum+=M[i][j];
        }
        if(sum>sumi)
            sumi=sum,sol_1=i;
        s_tot+=sum;
    }
    if(v==1LL)
    {
        printf("%d",sol_1);
        return 0;
    }
    for(sol_2=step=(1LL<<62); step; step/=2LL)
        if(sol_2-step>=s_tot)
            if(ok(sol_2-step))
                sol_2-=step;
    printf("%lld %lld",sol_2,sol_2-s_tot);
    return 0;

}