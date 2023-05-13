//#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#define x first
#define y second
using namespace std;
const int nmax=2*100000+10;//...x10ˆ5 + 10
int v[nmax];
struct mycmp
{
    bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs)
    {
        if(lhs.x==rhs.x)
            return lhs.y>rhs.y;
        return lhs.x<rhs.x;
    }
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x=1;
        scanf("%d",&n);
        auto cmp=[](pair<int,int> lhs,pair<int,int> rhs)
        {
            if(lhs.x==rhs.x)
                return lhs.y>rhs.y;
            return lhs.x<rhs.x;
        };
        priority_queue<pair<int,int>,vector<pair<int,int> >,mycmp>q;
        q.push({n,1});//lungime capat stanga
        while(!q.empty())
        {
            pair<int,int> t=q.top();
            q.pop();
            if(t.x==0 || t.y==0)
                continue;
            if(t.x==1)
                v[t.y]=x++;
            else
            {
                if(t.x%2==1)
            {
                v[t.y+t.x/2]=x++;
                q.push({t.x/2,t.y});
                q.push({t.x/2,t.y+t.x/2+1});
            }
            else
            {
                v[t.y+t.x/2-1]=x++;
                q.push({t.x/2,t.y+t.x/2});
                q.push({t.x/2-1,t.y});
            }
            }
        }
        for(int i=1;i<=n;++i)
            printf("%d ",v[i]);
        printf("\n");
    }
    return 0;
}