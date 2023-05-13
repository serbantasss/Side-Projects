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
int dist[NMAX+5], pre[NMAX+5];
bool inqueue[NMAX+5];

struct comp{
    bool operator()(int x,int y){
        return dist[x]>dist[y];
    }
};

int main() {
    freopen("dijkstra.in","r",stdin);
    freopen("dijkstra.out","w",stdout);
    int n, m, curr;
    scanf("%d %d",&n, &m);
    for(int i=1;i<=m;++i)
    {
        int x,y,cost;
        scanf("%d %d %d",&x,&y,&cost);
        adc[x].push_back({y,cost});
    }
    dist[1] = 0;
    for(int i=2;i<=n;++i)
        dist[i] = inf, pre[i] = -1;
    priority_queue<int, vector<int>, comp> pq;
    pq.push(1);
    inqueue[1] = 1;

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
    for(int i=2;i<=n;++i) {
        if (dist[i] != inf)
            printf("%d ", dist[i]);
        else
            printf("0 ");
    }
    /*for(int i=2;i<=n;++i)
        printf("%d ",pre[i]);*/
    return 0;
}