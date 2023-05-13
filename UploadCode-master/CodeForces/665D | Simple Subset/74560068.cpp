#include <bits/stdc++.h>
using namespace std;
const int nmax=2000000;
bool f[nmax+5];
int v[1005];
void ciur()
{
    f[0]=f[1]=1;
    for(int i=4;i<=nmax;i+=2)
        f[i]=1;
    for(int i=3;i*i<=nmax;i+=2)
        if(!f[i])
            for(int j=i*i;j<=nmax;j+=2*i)
                f[j]=1;
}
vector<int>pri;
int main()
{
    //    freopen("cocochanel.in","r",stdin);
    //    freopen("cocochanel.out","w",stdout);
    //ans=1 unn singur elem prim
    //ans=2 2 elem cu suma prim
    //ans>=3 1 1 1 .... 1 1 sau 1 1 1 .... 1 1 x unde x+1=prim
    int n,nr1=0,ans=0;
    int a=-1;//ans=1
    int b1=-1,b2=-1;//ans=2
    int c=-1;//ans=3
    ciur();
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
        if(v[i]==1)
            nr1++;
        if(!f[v[i]])
            a=v[i],ans=1;
        if(!f[v[i]+1] && v[i]!=1)
            c=v[i];
    }
    for(int i=1;i<=n && ans!=2;++i)
        for(int j=i+1;j<=n && ans!=2;++j)
            if(!f[v[i]+v[j]])
                b1=v[i],b2=v[j],ans=2;
    if(nr1 && c!=-1)
    {
        printf("%d\n",nr1+1);
        for(int i=1;i<=nr1;++i)
            printf("1 ");
        printf("%d",c);
        return 0;
    }
    if(nr1>=2)
    {
        printf("%d\n",nr1);
        for(int i=1;i<=nr1;++i)
            printf("1 ");
        return 0;
    }
    if(ans==2)
    {
        printf("2\n%d %d",b1,b2);
        return 0;
    }
    printf("1\n%d",v[1]);
    return 0;
}