//#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <numeric>
#define x first
#define y second
using namespace std;
const int nmax=2*100000+10;//...x10ˆ5 + 10
int v[nmax],st[nmax],dr[nmax];
struct mycmp
{
    bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs)
    {
        if(lhs.x==rhs.x)
            return lhs.y>rhs.y;
        return lhs.x<rhs.x;
    }
};
long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    long long int n,ans=1;
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&v[i]);
    st[1]=v[1],dr[n]=v[n];
    for(int i=2;i<=n;++i)
        st[i]=gcd(st[i-1],v[i]);
    for(int i=n-1;i>=1;--i)
        dr[i]=gcd(dr[i+1],v[i]);
    ans=dr[2];
    for(int i=1;i<n-1;++i)
    {
        ans=ans*gcd(st[i],dr[i+2])/gcd(gcd(st[i],dr[i+2]),ans);
    }
    ans=ans*st[n-1]/gcd(ans,st[n-1]);
    printf("%lld",ans);
    return 0;
}