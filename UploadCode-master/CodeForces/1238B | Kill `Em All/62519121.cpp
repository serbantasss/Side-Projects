#include <bits/stdc++.h>
using namespace std;
int f[100005];
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,r;
        scanf("%d%d",&n,&r);
        vector<int>v;
        int x;
        for(i=1; i<=n; ++i)
        {
            scanf("%d",&x);
            if(f[x]==0)
                v.push_back(x);
            f[x]=1;
        }
        sort(v.begin(),v.end());
        n=v.size();
        int k=1,s,shot=-1;
        for(i=n-1; i>=0; --i)
        {
            if(v[i]%r==0)
                s=v[i]/r;
            else
                s=v[i]/r+1;
            s=min(s,k);
            if(shot<s)
                shot=s;
            k++;
            f[v[i]]=0;
        }
        printf("%d\n",shot);
    }
    return 0;
}