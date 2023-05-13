#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int __gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return __gcd(b, a % b);
}
int main()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        int n;
        cin >> n;
 
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
 
        bool inf = true;
        int minval = a[0];
 
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[0])
            {
                inf = false;
                break;
            }
            minval = min(minval, a[i]);
        }
 
        if (inf)
        {
            cout << "-1\n";
            continue;
        }
 
        sort(a.begin(), a.end());
 
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = __gcd(ans, a[i] - minval);
        cout << abs(ans) << '\n';
    }
 
    return 0;
}