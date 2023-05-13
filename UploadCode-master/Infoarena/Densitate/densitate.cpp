#include <bits/stdc++.h>
using namespace std;
int c[500005];
void ciur(int nmax)
{
    c[1]=1;
    for(int i=4;i<=nmax;i+=2)
        c[i]=1;
    int sq=(int)sqrt((double)nmax);
    for(int i=3;i<=sq;i+=2)
        if(!c[i])
            for(int j=i*i;j<=nmax;j+=2*i)
                c[j]=1;
}
int main()
{
    freopen("densitate.in","r",stdin);
     freopen("densitate.out","w",stdout);
    int n,i,q,a,b;
    scanf("%d",&n);
    ciur(n);
    scanf("%d",&q);
    for(i=1;i<=n;++i)
        c[i]+=c[i-1];
    for(;q;--q)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",(b-a+1)-(c[b]-c[a-1]));
    }
    return 0;
}