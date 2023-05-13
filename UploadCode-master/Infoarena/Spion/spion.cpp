#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

#define ll long long
#define restRez 100003

using namespace std;

int caz;
string str;

ll putere(ll n, ll put) {
  ll rest = 1;

  for (; put > 1; put /= 2) {
    if (put % 2)
      rest = rest * n % restRez;
    n = n * n % restRez;
  }

  return n * rest % restRez;
}

int main()
{
  ifstream cin("spion.in");
  ofstream cout("spion.out");

  cin >> caz;

  cin >> str;

  int apar = 0;
  for (auto i : str)
    if (i == 'E')
      apar++;

  ll sol = 1;
  for (int i = apar + 1; i <= str.size(); i++)
    sol = sol * i % restRez;

  for (int i = str.size() - apar; i; i--)
    sol = sol * putere(i, restRez - 2) % restRez;

  cout << ((caz == 1)? apar + 1 : sol) << "\n";

  return 0;
}