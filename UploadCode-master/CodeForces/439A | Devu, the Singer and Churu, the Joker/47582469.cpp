#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,i,x,s,timpr=0,jok=0;
    cin>>n>>s;
    for(i=1;i<=n;++i)
    {
        cin>>x;
        timpr+=x;
    }
    if(timpr+(n-1)*10>s)
        cout<<-1;
    else
        cout<<(s-timpr)/5;
    return 0;
}