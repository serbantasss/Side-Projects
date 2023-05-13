#include <bits/stdc++.h>
using namespace std;
int v[200005];
set<long long> st;
int main()
{
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&v[i]);
    long long sum=0;
    for(int i=1;i<=n;++i)
    {
        sum+=v[i];
        if(sum==0)
            {
                ans++;
                sum=v[i];
                st.clear();
            }
        else
            if(st.find(sum)!=st.end())
            {
                ans++;
                st.clear();
                sum=v[i];
            }
        st.insert(sum);
    }
    printf("%lld",ans);
    return 0;
}