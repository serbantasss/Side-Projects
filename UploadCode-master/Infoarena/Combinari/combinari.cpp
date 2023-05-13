#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#define x first
#define y second
#define intmax 2000000000
using namespace std;
int v[20];
void back(int k,int val,int n,int m)
{
    if(val>n)
        return;
    for(int i=val;i<=n;++i)
    {
        v[k]=i;
        if(k<m)
            back(k+1,i+1,n,m);
        else
        {
            for(int j=1;j<=m;++j)
                printf("%d ",v[j]);
            printf("\n");
        }
    }
}
int main()
{
    freopen("combinari.in","r",stdin);
    freopen("combinari.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    back(1,1,n,m);
    return 0;
}