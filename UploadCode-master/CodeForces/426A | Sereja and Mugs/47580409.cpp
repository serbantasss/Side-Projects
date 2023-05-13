#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,ma=-1,i,stot=0,s,x;
    cin>>n>>s;
    for(i=1;i<=n;++i)
    {
        cin>>x;
        if(x>ma)
            ma=x;
        stot+=x;
    }
    if(s<stot-ma)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}