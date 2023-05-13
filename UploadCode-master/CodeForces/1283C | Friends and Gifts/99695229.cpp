#include <bits/stdc++.h>
using namespace std;
int v[200005];
deque<int> c;
unordered_map<int,int> m;
int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]!=0)
            m[v[i]]=1;
        else
            cnt++;
    }
    for(int i=n;i>=1;i--)
        if(m[i]!=1)
            c.push_back(i);
    int j=0;
    int ind2=-1,ind1=-1;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            if(cnt==2)
                ind2=i;
            if(cnt==1)
                ind1=i;
            if(c.front()==i+1)
            {
                v[i]=c.back();
                c.pop_back();
            }
            else
            {
                v[i]=c.front();
                c.pop_front();
            }
            cnt--;
        }
    }
    if(ind2!=-1 && v[ind1]==ind1+1)
        swap(v[ind1],v[ind2]);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}