#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const int N = 3e5 + 10;
int n, m, k;
int ans[N], F[N];
vector < pair < int, pair < int, int > > > g[N];
priority_queue < pair < ll, pair < int, int > > > pq;
int main() {
    cin >> n >> m >> k;
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, {w, i}});
        g[v].push_back({u, {w, i}});
    }
    pq.push({0, {1, 0}});
    ll l = 0, res = 0, d = 0;
    while(!pq.empty()) {
        l = -pq.top().f;
        v = pq.top().s.f;
        d = pq.top().s.s;
        pq.pop();
        if(F[v]) continue;
        F[v] = 1;
        if(v != 1) {
            if(res + 1 > k) break;
            res++;
            ans[res] = d;
        }
        for(int i = 0; i < g[v].size(); i++) {
            pq.push({- l - g[v][i].s.f, {g[v][i].f, g[v][i].s.s}});
        }
    }
    cout << res << "\n";
    for(int i = 1; i <= res; i++) cout << ans[i] << " ";
    cout << "\n";
}
    