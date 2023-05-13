#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#define x first
#define y second
using namespace std;
const int nmax=100005;//2x10ˆ5 + 5
int v[nmax];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,ok=1;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&v[i]);
        for(int i=1;i<n && ok;++i)
            if(v[i]<v[i+1] && v[i+1]-v[i]>1)
                ok=0;
        if(ok)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}