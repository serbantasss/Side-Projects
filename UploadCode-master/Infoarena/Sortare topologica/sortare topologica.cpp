///dezbateri campion
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 50005
int N, M, viz[MAXN], deg[MAXN];
vector<int> afisare;
vector<int> G[MAXN];
void solve_and_write(void)
{
    
    for(int i = 1; i <= N; i++)
        if(deg[i] == 0)
            afisare.push_back(i);
    for(int i = 0; i < N; i++)
    {
        int nod=afisare[i];
        for(int j : G[nod])
        {
            deg[j]--;
            if(!deg[j])
                afisare.push_back(j);
            
        }
    }
    for(int i : afisare)
        printf("%d ",i);
}
void read_data(void)
{
    int i,a,b;
    scanf("%d %d\n", &N, &M);
    for(i = 1; i <= M; i++)
    {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        deg[b]++;
    }
}
int main()
{
    freopen("sortaret.in", "rt", stdin);
    freopen("sortaret.out", "wt", stdout);
    read_data();
    solve_and_write();
    return 0;
}