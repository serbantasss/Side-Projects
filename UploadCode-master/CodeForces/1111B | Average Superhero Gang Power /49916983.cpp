#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
int arr[MAXN];
double ans;
int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 0; i < n && i <= m; i++) {
        sum -= arr[i];
        ans = max(ans, (sum + min(1LL * m - i, 1LL * k * (n - i))) * 1.0 / (n - i));
    }
    printf("%.20lf", ans);
    return 0;
}