#include <bits/stdc++.h>
using namespace std;
struct lap
{
    int p,q;
};
lap v[100005];
bool cmp(lap a,lap b)
{
    if(a.p==b.p)
        return a.q<b.q;
    return a.p<b.p;
}
int main()
{
    int n,i,j,k,p,q;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        {
        scanf("%d%d",&p,&q);
        v[i].p=p;
        v[i].q=q;
        }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n-1;++i)
            if(v[i].p<v[i+1].p && v[i].q>v[i+1].q)
    {
        printf("Happy Alex");
        return 0;
    }
    printf("Poor Alex");
    return 0;
}