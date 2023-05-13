#include <bits/stdc++.h>
using namespace std;
struct intt
{
    int ind,nr;
    bool s;
};
intt a[100005],b[100005],c[200005];
bool cmp(intt x,intt y)
{
    return x.nr<y.nr;
}
bool f1[100005],f2[100005];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    j=1;
    for(i=1;i<=n;++i)
    {
        intt x;
        int ci;
        scanf("%d",&ci);
        a[i].nr=ci;
        a[i].ind=i;
        a[i].s=0;
        scanf("%d",&ci);
        b[i].nr=ci;
        b[i].ind=i;
        b[i].s=1;
        c[j++]=a[i];
        c[j++]=b[i];
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    sort(c+1,c+2*n+1,cmp);
    for(i=1;i<=n/2;++i)
        f1[a[i].ind]=1,f2[b[i].ind]=1;
    for(i=1;i<=n;++i)
        if(c[i].s==0)
            f1[c[i].ind]=1;
        else
            f2[c[i].ind]=1;
    for(i=1;i<=n;++i)
        printf("%d",f1[i]);
    printf("\n");
    for(i=1;i<=n;++i)
        printf("%d",f2[i]);
    return 0;
}
 