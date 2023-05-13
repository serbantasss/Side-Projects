#include <bits/stdc++.h>
using namespace std;
int f[1005];
int main()
{
    int n,i,x,k,ans=0,y=0;
    cin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        ans+=x;
    }
    if(ans>0)
    {
        for(i=k; i>=1 && ans!=0; --i)
            while(ans>=i)
                ans-=i,y++;
    }
    else if(ans<0)
    {
        for(i=k; i>=1 && ans!=0; --i)
            while(ans<=-i)
                ans+=i,y++;
    }
    cout<<y;
    return 0;
}