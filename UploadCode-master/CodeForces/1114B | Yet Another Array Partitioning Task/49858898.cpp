#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll arr[200005], arr2[200005];
map<ll, ll> mymap;
vector<int> idx;
bool mycomp(ll a, ll b){
 return a > b;
}
int main(){
 int n, m, k;
 cin >> n >> m >> k;
 ll sum = 0;
 for(int i = 0; i < n; i++){
  cin >> arr[i];
  arr2[i] = arr[i];
  sum += arr[i];
 }
 if(m == 1 && k == n){
  cout << sum << endl;
  for(int i = 0; i < n - 1; i++){
   cout << i + 1 << " ";
  }
  return 0;
 }
 sort(arr, arr + n, mycomp);
 int len = k*m;
 ll sum1 = 0;
 for(int i = 0; i < len; i++){
  mymap[arr[i]]++;
  sum1 += arr[i];
 }
 int cnt = 0;
 int tot_cnt = 0;
 for(int i = 0; i < n; i++){
  if(mymap[arr2[i]] > 0){
   cnt++;
   mymap[arr2[i]]--;
  }
  if(cnt == m){
   idx.push_back(i + 1);
   cnt = 0;
   tot_cnt++;
  }
  if(tot_cnt == k - 1) break;
 }
 len = idx.size();
 cout << sum1 << endl;
 for(int i = 0; i < len; i++){
  cout << idx[i] << " ";
 }
 return 0;
}