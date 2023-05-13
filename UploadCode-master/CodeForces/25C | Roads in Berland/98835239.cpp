#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#define x first
#define y second
using namespace std;
int adc[305][305];
void afis(int n)
{
    long long s=0;
    for(int i=1;i<=n;++i)
    for(int j=i+1;j<=n;++j)
    s+=adc[i][j];
    printf("%lld ",s);
}
int main()
{
    int n,k,ok=1;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    scanf("%d",&adc[i][j]);
    scanf("%d",&k);
    for(int i=1;i<=k;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(adc[a][b]<c)
            afis(n);
        else
        {
            adc[a][b]=adc[b][a]=c;
            for(int i=1;i<=n;++i)
                for(int j=i+1;j<=n;++j)
                {
                    if(adc[a][i]+adc[b][j]+c<adc[i][j])
                        adc[i][j]=adc[j][i]=adc[a][i]+adc[b][j]+c;
                    if(adc[a][j]+adc[b][i]+c<adc[i][j])
                        adc[i][j]=adc[j][i]=adc[a][j]+adc[b][i]+c;
                }
            afis(n);
        }
    }
    return 0;
}