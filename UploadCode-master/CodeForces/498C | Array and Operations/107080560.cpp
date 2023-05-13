#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
 
const int MAXN = 10000;
 
int n,m,code,N,tot;
int mark[MAXN],match[MAXN];
vector <int> qq[MAXN];
vector <int> adj[MAXN];
map <int,int> mp;
vector < pair<int,int> > q[MAXN];
 
vector < pair<int,int> > factorize (int x)
{
    vector < pair<int,int> > ret;
    for (int i=2; i*i<=x; i++)
    {
        int cnt = 0;
        while (x % i == 0)
            x/=i,cnt++;
        if (cnt != 0)
        {
            if (mp.find(i) == mp.end())
                mp[i] = tot++;
            ret.push_back({mp[i],cnt});
        }
    }
    if (x != 1)
    {
        if (mp.find(x) == mp.end())
            mp[x] = tot++;
        ret.push_back({mp[x],1});
    }
    return ret;
}
 
bool dfs (int v)
{
    if (v == -1)
        return 1;
    if (mark[v] == code)
        return 0;
    mark[v] = code;
    for (int i=0; i<adj[v].size(); i++)
    {
        int temp = adj[v][i];
        if (dfs(match[temp]))
        {
            match[temp] = v;
            match[v] = temp;
            return 1;
        }
    }
    return 0;
}
 
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        q[i] = factorize(x);
        for (int j=0; j<(int)q[i].size(); j++)
        {
            qq[i].push_back(N);
            N+= q[i][j].second;
        }
    }
    for (int i=0; i<m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        for (int j=0; j<q[a].size(); j++)
            for (int k=0; k<q[b].size(); k++)
                if (q[a][j].first == q[b][k].first)
                    {
                        for (int l=0; l<q[a][j].second; l++)
                            for (int t=0; t<q[b][k].second; t++)
                                {
                                    adj[qq[a][j]+l].push_back(qq[b][k]+t);
                                    adj[qq[b][k]+t].push_back(qq[a][j]+l);
                                }
        }
    }
    memset(match, -1, sizeof match);
    int ans = 0;
    for (int i=0; i<N; i++)
    if (match[i] == -1)
        for (int j=0; j<adj[i].size(); j++)
            if (match[adj[i][j]] == -1)
                {
                    match[i] = adj[i][j];
                    match[adj[i][j]] = i;
                    ans++;
                    break;
                }
    for (int i=0; i<N; i++)
        if (match[i] == -1)
            {
                code++;
                if (dfs(i))
                    ans++;
            }
    printf("%d",ans);
    return 0;
}