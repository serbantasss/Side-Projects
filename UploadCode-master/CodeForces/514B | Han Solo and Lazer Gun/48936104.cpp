#include <bits/stdc++.h>
using namespace std;
vector < pair<int,int> > v;
int main()
{
    int n,m,k,i,j,ar,y,x,xo,yo;
    scanf("%d%d%d",&n,&x,&y);
    scanf("%d%d",&xo,&yo);
    v.push_back(make_pair(xo,yo));
    for(i=2; i<=n; ++i)
    {
        scanf("%d%d",&xo,&yo);
        int ok=1;
        for(j=0; j<v.size(); ++j)
            if(x * (yo - v[j].second) + xo * (v[j].second - y) + v[j].first * (y - yo)==0)
            {
                ok=0;
                break;
            }
        if(ok==1)
            v.push_back(make_pair(xo,yo));
    }
    printf("%d",v.size());
    return 0;
}