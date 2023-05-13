#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x,ma=-1,k=0;
    char ch;
    long long p2=1,ans=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>ch;
        if(ch=='B')
            ans+=p2;
        p2*=2;
    }
    cout<<ans;
    return 0;
}