#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
const int N = 200 * 1000 + 13;
 
typedef long long li;
 
int n;
int a[N];
 
void get(li T, li& pr, li& cnt){
 pr = 0, cnt = 0;
 forn(i, n){
  if (T >= a[i]){
   T -= a[i];
   pr += a[i];
   ++cnt;
  }
 }
}
 
int main() {
 li T;
 scanf("%d%lld", &n, &T);
 forn(i, n)
  scanf("%d", &a[i]);
 
 int mn = *min_element(a, a + n);
 li ans = 0;
 while (T >= mn){
  li pr, cnt;
  get(T, pr, cnt);
  ans += cnt * (T / pr);
  T %= pr;
 }
 printf("%lld\n", ans);
 return 0;
}