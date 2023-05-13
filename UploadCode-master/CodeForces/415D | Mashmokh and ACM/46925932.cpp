#include <cstdio>
#include <vector>
 
using namespace std;
long long  mat[2005][2005];
vector<long long >div[2005];
int main()
{
    long long n,k,i,j,m=1000000007,x;
    long long  sum=0;
    scanf("%lld%lld",&n,&k);
    for(i=1;i<=2000;++i)
        for(j=i;j<=2000;j+=i)
            div[j].push_back(i);
    for(i=1;i<=n;++i)
        mat[i][1]=1;
    for(i=1;i<=n;++i)
        for(j=2;j<=k;++j)
            for(x=0;x<div[i].size();++x)
                mat[i][j]=(mat[i][j]+mat[div[i][x]][j-1])%m;
    for(i=1;i<=n;++i)
        sum+=mat[i][k];
    printf("%lld",sum%m);
    return 0;
}