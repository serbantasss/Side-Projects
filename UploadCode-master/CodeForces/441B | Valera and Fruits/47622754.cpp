#include <iostream>
 
using namespace std;
 
int n, v, a, b, z[300001], urm[300001], k, total;
 
int main()  {
  cin >> n >> v;
  for (int i = 1; i <= n; ++i)  {
    cin >> a >> b;
    z[a] += b;
    urm[a] += b;
  }
  for (int i = 1; i <= 300000; ++i)  {
    k = z[i];
    total += min(k, v);
    k -= min(k, v);
    z[i + 1] += min(urm[i], k);
  }
  cout << total;
  return 0;
}