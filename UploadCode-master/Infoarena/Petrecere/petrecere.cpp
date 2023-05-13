#include <cstdio>
#include <algorithm>
using namespace std;
int a[6005],b[6005],c[6005];

int main()
{
	freopen("petrecere.in","r",stdin);
	freopen("petrecere.out","w",stdout);
    int n,i,k,t,m;
    scanf("%d",&n);
    if(n==1)
        printf("1");
    if(n==2)
        printf("2");
    a[0]=b[0]=a[1]=b[1]=1;
    b[1]++;
    for(i=3;i<=n;++i)
    {
        ///c=b;
        for(k=0;k<=b[0];++k)
            c[k]=b[k];
        ///a=a*(i-1);
        m=i-1,t=0;
        for(k=1;k<=a[0];k++,t/=10)
        {
            t+=a[k]*m;
            a[k]=t%10;
        }
        for(;t;t/=10)
            a[++a[0]]=t%10;
        ///c+=a;
        t=0;
        if(c[0]<a[0])
            c[0]=a[0];
        for(k=1;k<=c[0];++k,t/=10)
        {
            t=c[k]+a[k]+t;
            c[k]=t%10;
        }
        if(t)
            c[++c[0]]=t;
        ///a=b;
        for(k=0;k<=b[0];++k)
            a[k]=b[k];
        ///b=c;
        for(k=0;k<=c[0];++k)
            b[k]=c[k];
    }
    for(i=c[0];i>=1;--i)
        printf("%d",c[i]);
    return 0;
}