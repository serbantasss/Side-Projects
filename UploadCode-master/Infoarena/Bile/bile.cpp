#include <cstdio>
#include <algorithm>
using namespace std;
const int nmax=250*250+5;
pair <int , int> v[nmax];
int n,answer[nmax],nrelem[nmax],tree[nmax];
int find_root(int nod)
{
    int radacina = nod;
    int y = nod;
    while (radacina != tree[radacina])
    {
        radacina = tree[radacina];
    }
    while (nod != tree[nod])
    {
        y = tree[nod];
        tree[nod] = radacina;
        nod = y;
    }
    return radacina;
}
int main()
{
    freopen("bile.in","r",stdin);
   freopen("bile.out","w",stdout);
    scanf("%d",&n);
    for(int i =0;i<n*n;i++)
        scanf("%d%d",&v[i].first,&v[i].second);
    for(int i=1;i<=n*n;i++)
        tree[i] = -1,nrelem[i] = 0;
    int ma = -1;
    int dx[5]={0,-1,1,0,0};
    int dy[5]={0,0,0,1,-1};
    int vec[5];
    vec[0] = -2;
    for (int i = n*n-1;i>=0;i--)
    {
        int x = v[i].first;
        int y = v[i].second;
        int nod = (x - 1) * n + y;
        tree[nod] = nod;
        nrelem[nod] ++;
        for (int j = 1;j<=4;j++)
        {
            int x1 = x + dx[j];
            int y1 = y + dy[j];
            int nod1 = (x1 - 1) * n + y1;
            int root;
            vec[j] = -1;
            if ((x1 > 0 && x1 <= n) && (y1 > 0 && y1 <= n))
            {
               if (tree[nod1] != -1)
               {
                   vec[j] = find_root(nod1);
               }
            }
        }
        sort(vec,vec+5);
        for(int j = 1;j<=4;j++)
        {
            if (vec[j] > 0 && vec[j] != vec[j-1])
            {
                tree[vec[j]] = nod;
                nrelem[nod] += nrelem[vec[j]];
            }
        }
        if(ma<nrelem[nod])
            ma=nrelem[nod];
        answer[i+1] =ma;
    }
    for(int i=3;i<=n*n+2;i++)
        printf("%d\n",answer[i-1]);
    return 0;
}