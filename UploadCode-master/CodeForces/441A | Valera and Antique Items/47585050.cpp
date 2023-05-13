#include <bits/stdc++.h>
using namespace std;
vector<int> q;
int main()
{
    int n,i,x,s,timpr=0,ok=0,p;
    cin>>n>>s;
    for(i=1;i<=n;++i)
    {
        cin>>x;
        ok=0;
        for(int j=1;j<=x;++j)
        {
            cin>>p;
            if(p<s)
                ok=1;
        }
        if(ok)
            q.push_back(i);
    }
    cout<<q.size()<<endl;
    for(i=0;i<q.size();++i)
        cout<<q[i]<<" ";
    return 0;
}