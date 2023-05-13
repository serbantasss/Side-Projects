#include <bits/stdc++.h>
using namespace std;
int f[5005];
vector<int>v;
int main()
{
    int n,i,x,ma=-1,k=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>x;
        f[x]++;
        if(ma<x)
            ma=x;
    }
    vector<int>::iterator it;
    v.push_back(ma);
    for(i=ma-1;i>=1;--i)
    {
        if(f[i]==1)
        {
            v.push_back(i);
        }
        if(f[i]>=2)
        {
           v.push_back(i);
           it=v.begin();
           v.insert(it,i);
        }
    }
    cout<<v.size()<<endl;
    for(i=0;i<v.size();++i)
        cout<<v[i]<<" ";
    return 0;
}