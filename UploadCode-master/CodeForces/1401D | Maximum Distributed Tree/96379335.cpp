#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 
void dfs(int node,int par,vector<int> g[],vector<ll> &size)
{
 for(int x:g[node])
 {
  if(x == par) continue;
  dfs(x,node,g,size);
  size[node] += size[x];
 }
 size[node]++;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,x,y;
  cin>>n;
  vector<int> g[n];
  for(int i=0;i<n-1;i++) cin>>x>>y,x--,y--,g[x].push_back(y),g[y].push_back(x);
  int m;
  cin>>m;
  ll cost[m];
  for(ll &num:cost) cin>>num;
  vector<ll> size(n,0);
  dfs(0,0,g,size);
  for(ll &num:size) num = ((n - num)*num);
  sort(size.begin(),size.end(),greater<ll>());
  sort(cost,cost+m,greater<ll>());
  for(ll &num:size) num = num%mod;
  ll ans = 0,ed = n-1;
  if(m > ed)
  {
   ans = size[0];
   for(int i=0;i<m-ed+1;i++) ans = (ans * cost[i])%mod;
   for(int i=m-ed+1;i<m;i++) ans = (ans+ (cost[i]*size[i - m +ed]))%mod;
  }
  else{
   for(int i=0;i<m;i++) ans = (ans+(cost[i] * size[i]))%mod;
   for(int i=m;i<ed;i++) ans = (ans + size[i])%mod;
  }
  cout<<ans<<'\n';
 }
 return 0;
}