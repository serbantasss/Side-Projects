#include <iostream>
#include <algorithm>
using namespace std;
int v[100005];
int main()
{
 int n,i,j,ch;
 long long x,ans=0,k;
 cin>>n>>x;
 for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    k=x;
    for(i=1;i<=n;++i)
    {
        ans=ans+(long long)v[i]*k;
        if(k>1)
            k--;
    }
    cout<<ans;
 return 0;
}