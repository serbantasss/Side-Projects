#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>

#define next_node adc[curr][i].first
#define distance adc[curr][i].second
using namespace std;
const auto NMAX = 200005, MMAX = 400005;
const int inf = 1<<29;

struct edge{
    int x, y, w;
}v[MMAX+5];
bool cmp(edge a, edge b){
    return a.w<b.w;
}
vector<pair<int,int>> mst;
int n, m, ans;
int subtree[NMAX+5], size_subtree[NMAX+5];
int find_set(int x){
    while(subtree[x]!=x)
        x = subtree[x];
    return x;
}
int main() {
    freopen("apm.in","r",stdin);
    freopen("apm.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
        scanf("%d%d%d",&v[i].x, &v[i].y, &v[i].w);
    for(int i=1;i<=n;++i)
        subtree[i] = i, size_subtree[i] = 1;
    sort(v+1,v+m+1, cmp);
    for(int i=1;i<=m;++i){
        int x= v[i].x, y= v[i].y, w= v[i].w;
        int oldtree = find_set(y), newtree = find_set(x);
        if(oldtree != newtree){
            if(size_subtree[oldtree] == size_subtree[newtree]){
                size_subtree[newtree]++;
                subtree[oldtree] = newtree;
            }else{
                if(size_subtree[oldtree] < size_subtree[newtree])
                    subtree[oldtree] = newtree;
                else
                    subtree[newtree] = oldtree;
            }
            mst.emplace_back(x,y);
            ans+=w;
        }
    }
    printf("%d\n%d\n", ans, mst.size());
    for(auto & i : mst)
        printf("%d %d\n",i.first, i.second);
    return 0;
}