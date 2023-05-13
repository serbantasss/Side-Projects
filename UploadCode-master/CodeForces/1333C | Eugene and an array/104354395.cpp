#include <bits/stdc++.h>
using namespace std;
long long v,sp[200005],ans=0;
map<long long,bool> mp;
int main()
{
    int n,st=1,dr=1;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&v);
        sp[i+1]=sp[i]+v;
    }
    mp[0]=1;
    while(st<=n)
    {
        while(dr<=n && !mp[sp[dr+1]])
        {
            dr++;
            mp[sp[dr]]=1;
        }
        ans+=dr-st;
        mp[sp[st]]=0;
        st++;
    }
    printf("%lld",ans);
    return 0;
}