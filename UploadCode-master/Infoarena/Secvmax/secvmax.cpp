#include <bits/stdc++.h>
using namespace std;
const int nmax=200005;
int st[nmax],best[nmax],v[nmax],ind[nmax],sol[nmax];
stack<int> stiva;
map<int,int> mp;
vector< pair<int,int> > ans;
bool mycmp(int a,int b)
{
    return v[a]<v[b];
}
int main()
{
    freopen("secvmax.in","r",stdin);
    freopen("secvmax.out","w",stdout);
    int n,i,q,x,y = 0,mi=INT_MAX;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
        if(mi>v[i])
            mi=v[i];
    }
    //stanga
    stiva.push(1);
    st[1]=1;
    for(i=2;i<=n;++i)
    {
        if(v[i-1]>v[i])
        {
            st[i]=1;
            stiva.push(i);
        }
        else
        {
            while(!stiva.empty() && v[stiva.top()]<=v[i])
                stiva.pop();
            if(stiva.empty())
                st[i]=i;
            else
                st[i]=i-stiva.top();
            stiva.push(i);
        }
    }
    while(!stiva.empty())
        stiva.pop();
    //dreapta
    stiva.push(n);
    best[n]=st[n];
    ind[n]=n;
    for(i=n-1;i>=1;--i)
    {
        ind[i]=i;
        if(v[i+1]>v[i])
        {
            best[i]=st[i];
            stiva.push(i);
        }
        else
        {
            while(!stiva.empty() && v[stiva.top()]<=v[i])
                stiva.pop();
            if(stiva.empty())
                best[i]=n-i+st[i];
            else
                best[i]=stiva.top()-i+st[i]-1;
            stiva.push(i);
        }
    }
    sort(ind+1,ind+n+1,mycmp);
    int k=0;
    for(i=1;i<=n;++i)
    {
        ind[++k]=ind[i];
        for(;v[ind[k]]==v[ind[i+1]];++i)
            best[ind[k]]=max(best[ind[k]],best[ind[i+1]]);
    }
    n=k;
    for(i=1; i<=n; ++i)
        sol[i]=max(sol[i-1],best[ind[i]]);
    for(i=1;i<=q;++i)
    {
        scanf("%d",&x);
        if(x<mi)
            printf("0\n");
        else
        {
            int stg=1,drg=n,mid;
            y=0;
            while(stg<=drg)
            {
                mid=(stg+drg)/2;
                if(x>=v[ind[mid]])
                    y=mid,stg=mid+1;
                else
                    drg=mid-1;
            }
            if(v[ind[y]]>x)
                --y;
            printf("%d\n",sol[y]);
        }
    }
    /*for(i=1;i<=n;++i)
    {
        x=st[i]+dr[i]-1;
        if(mp[v[i]]<x)
            mp[v[i]]=x;
    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it)
        ans.push_back(make_pair(it->first,it->second));
    for(i=1;i<=q;++i)
    {
        scanf("%d",&x);
        int stg=0,drg=ans.size()-1,mid,y2;
        if(x<ans[0].first)
        {
            printf("0\n");
            continue;
        }
        while(stg<=drg)
        {
            mid=(stg+drg)/2;
            if(ans[mid].first<=x)
                y=mid,stg=mid+1;
            else
                drg=mid-1;
        }
        if(ans[y].first>x)
            y--;
        printf("%d\n",ans[y].second);
    }*/
    return 0;
}