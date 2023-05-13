#include <bits/stdc++.h>
using namespace std;
pair<int,int> v[100005];
int main()
{
    freopen("permutari3.in","r",stdin);
    freopen("permutari3.out","w",stdout);
    int t=0,n,m,i,j,st,dr;
    char ch;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&v[i].first);
        v[i].second=i;
    }
    sort(v+1,v+n+1);
    st=v[1].second;
    dr=v[1].second;
    for(i=2;i<=n;++i)
    {
        if(st>v[i].second)
            st=v[i].second;
        if(dr<v[i].second)
            dr=v[i].second;
        if(dr-st+1==i)
            t++;
    }
    printf("%d",t+1);
    return 0;
}