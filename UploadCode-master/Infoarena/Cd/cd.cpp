#include <cstdio>
using namespace std;
int v[305];
int main()
{
    freopen("cd.in","r",stdin);
    freopen("cd.out","w",stdout);
    int n,i,s,c,y;
    scanf("%d%d",&n,&s);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&y,&c);
        v[i]+=s/n+y;
        v[c]-=y;
    }
    y=1;
    for(i=1;i<=n;++i) y=(y*(v[i]-1))%9901;
    printf("%d",y);
    return 0;
}