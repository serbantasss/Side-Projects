#include <bits/stdc++.h>
using namespace std;
struct intt
{
    int val,ind;
};
intt v[100005];
bool cmp(intt a,intt b)
{
    if(a.val==b.val)
        return a.ind<b.ind;
    return a.val<b.val;
}
int main()
{
    //freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int n,i,j,x,l,lmax=0,ok;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%1d",&x);
        v[i].ind=i;
        v[i].val=v[i-1].val+x;
        if(x==0)
            v[i].val--;
    }
    v[i].val=0;
    v[i].ind=0;
    sort(v,v+n+1,cmp);
    ok=0;
    for(i=0; i<n; ++i)
        if(v[i].val==v[i+1].val)
        {
            ok=1;
            x=i;
            while(v[i].val==v[i+1].val && i+1<=n)
                i++;
            if(v[i].ind-v[x].ind>lmax)
                lmax=v[i].ind-v[x].ind;
        }
    if(ok==0)
        printf("0");
    else
        printf("%d",lmax);
    return 0;
}