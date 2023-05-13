#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> adc[50005];
vector<vector<int>> conex_comp;
int nr[50005], lowlink[50005], nrnod;
bool instack[50005];
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
    freopen("retele.in","r",stdin);
    freopen("retele.out","w",stdout);
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
    for(int i=0;i<conex_comp.size();++i)
        sort(conex_comp[i].begin(),conex_comp[i].end());
    sort(conex_comp.begin(),conex_comp.end());
    printf("%d\n", conex_comp.size());
    for(int i=0;i<conex_comp.size();++i){
        printf("%d ",conex_comp[i].size());
        for(int j=0;j<conex_comp[i].size();++j)
            printf("%d ",conex_comp[i][j]);
        printf("\n");
    }
    return 0;
}