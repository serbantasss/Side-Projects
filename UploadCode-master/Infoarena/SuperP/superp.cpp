#include<cstdio>
using namespace std;
int v[10];
bool prim(long long x)
{
    if((x%2==0 && x>2)||x==1)
        return 0;
    for(long long d=3;d*d<=x;d+=2)
        if(x%d==0)
            return 0;
    return 1;
}
long long dfs(long long x,int cif[])
{
    long long m=x,d;
    for(int i=9;i>=1;i--)
        if((i%2==1 || i==2)&&cif[i]>0 && prim(x*10+i))
        {
            cif[i]--;
            d=dfs(x*10+i,cif);
            if(m<d)
                m=d;
            cif[i]++;
        }
    return m;
}
int main()
{
    freopen("superp.in","r",stdin);
    freopen("superp.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x;
        scanf("%lld",&x);
        while(x)
        {
            v[x%10]++;
            x/=10;
        }
        printf("%lld\n",dfs(0LL,v));
        for(int i=1;i<=9;++i)
            v[i]=0;
    }
    return 0;
}