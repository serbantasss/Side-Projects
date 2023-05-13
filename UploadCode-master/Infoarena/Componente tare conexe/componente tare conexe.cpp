#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> adc[100005];
vector<vector<int>> conex_comp;
int nr[100005], lowlink[100005], nrnod;
bool instack[100005];
stack<int> stiva;

void dfs(int nod){
    nr[nod] = lowlink[nod] = nrnod;
    nrnod++;
    stiva.push(nod);
    instack[nod] = 1;
    for(int i=0; i<adc[nod].size(); ++i)
        if(nr[adc[nod][i]] == 0) {
            dfs(adc[nod][i]);
            lowlink[nod] = min(lowlink[adc[nod][i]], lowlink[nod]);
        } else {
            if (instack[adc[nod][i]])
                lowlink[nod] = min(lowlink[nod], lowlink[adc[nod][i]]);
        }
    if(lowlink[nod] == nr[nod]){
        vector<int> prov;
        int curr;
        do{
            curr = stiva.top();
            prov.push_back(curr);
            instack[curr] = 0;
            stiva.pop();
        }while(curr != nod);
        conex_comp.push_back(prov);
    }
}
int main()
{
    freopen("ctc.in","r",stdin);
    freopen("ctc.out","w",stdout);
    int n, m, x, y;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%d %d",&x,&y);
        adc[x].push_back(y);
    }
    nrnod = 1;
    for(int i=1;i<=n;++i)
        if(nr[i] == 0)
            dfs(i);
    printf("%d\n", conex_comp.size());
    for(int i=0;i<conex_comp.size();++i){
        for(int j=0;j<conex_comp[i].size();++j)
            printf("%d ",conex_comp[i][j]);
        printf("\n");
    }
    return 0;
}