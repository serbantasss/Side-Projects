#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,a,b,x,y,k;
int v[105];
int main()
{
    scanf("%d",&n);
    scanf("%d%d",&a,&b);
    for(i=2;i<=n;++i)
    {
        scanf("%d%d",&x,&y);
        for(int j=x+1;j<=y;++j)
            v[j]=1;
    }
    for(i=a+1;i<=b;++i)
        if(v[i]==0)
            k++;
    printf("%d",k);
    return 0;
}