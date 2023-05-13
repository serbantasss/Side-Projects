#include <bits/stdc++.h>
using namespace std;
int coco[100005],gaina[100005];
int cb(int elem,int m,int j)
{
    int st=j,dr=m,mid;
    if(elem>gaina[m])
        return m+1;
    while(st<=dr)
    {
        mid=(st+dr)/2;
        if(elem>gaina[mid])
            st=mid+1;
        else
            dr=mid-1;
    }
    return mid;
}
int main()
{
    freopen("cocochanel.in","r",stdin);
    freopen("cocochanel.out","w",stdout);
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
        scanf("%d",&coco[i]);
    for(i=1;i<=m;++i)
        scanf("%d",&gaina[i]);
    sort(gaina+1,gaina+m+1);
    for(i=1;i<=n;++i)
    {
        int cnt=0,cpy=coco[i],ind;
        j=1;
        while(j<=m)
        {
            ind=cb(cpy,m,j);
            if(ind<=m)
                cnt++;
            cpy*=2;
            j=ind+1;
        }
        printf("%d\n",cnt);
    }
    return 0;
}