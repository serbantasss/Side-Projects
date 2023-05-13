#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int N = 6e6;
pair<int, pair<int, int>> mp[N];
int main()
{
    int n;
    scanf("%d",&n);
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n ; i++) {
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = a[i].first + a[j].first;
            if(mp[sum].first)
            {
               if(mp[sum].second.first == a[i].second || mp[sum].second.second == a[i].second || mp[sum].second.first == a[j].second || mp[sum].second.second == a[j].second)
                   continue;
                printf("YES\n%d %d %d %d\n",a[i].second + 1,a[j].second + 1,mp[sum].second.first + 1,mp[sum].second.second + 1);
               return 0;
            }
            else
            {
               mp[sum] = {1, {a[i].second, a[j].second}};
            }
        }
    }
    printf("NO\n");
    return 0;
}