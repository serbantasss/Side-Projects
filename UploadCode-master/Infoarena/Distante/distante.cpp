#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>

#define next_node adc[curr][i].first
#define distance adc[curr][i].second
using namespace std;
const int NMAX = 50000;
const int inf = 1<<29;
vector<pair<int,int>> adc[NMAX+5];
int dist[NMAX+5], pre[NMAX+5], distcomp[NMAX+5];
bool inqueue[NMAX+5];

struct comp{
    bool operator()(int x,int y){
        return dist[x]>dist[y];
    }
};

int main() {
    freopen("distante.in","r",stdin);
    freopen("distante.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m, s, curr;
        scanf("%d %d %d",&n, &m, &s);
        for(int i=1;i<=n;++i)
            scanf("%d", &distcomp[i]),adc[i].clear();
        for(int i=1;i<=m;++i)
        {
            int x,y,cost;
            scanf("%d %d %d",&x,&y,&cost);
            adc[x].push_back({y,cost});
            adc[y].push_back({x,cost});
        }
        for(int i=1;i<=n;++i)
            dist[i] = inf, pre[i] = -1;
        dist[s] = 0;
        priority_queue<int, vector<int>, comp> pq;
        pq.push(s);
        inqueue[s] = 1;

        while(!pq.empty()){
            curr = pq.top();
            pq.pop();
            inqueue[curr] = 0;
            for(int i=0;i<adc[curr].size();++i) {
                if (dist[next_node] > dist[curr] + distance) {
                    dist[next_node] = dist[curr] + distance;
                    pre[next_node] = curr;
                    if (inqueue[next_node] == 0) {
                        pq.push(next_node);
                        inqueue[next_node] = 1;
                    }
                }
            }
        }
        bool ok = true;
        for(int i=1;i<=n && ok;++i) {
            if (dist[i] != distcomp[i])
                ok = false;
        }
        if(ok)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}