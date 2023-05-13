#include <fstream>

using namespace std;
int cost[]= {0,1,5,10,50,100,500};
int v[10];
int main()
{
    freopen("bancomat.in","r",stdin);
    freopen("bancomat.out","w",stdout);
    int t,i,j,n,ok,sum,d,nr;
    scanf("%d",&t);
    for(j=1; j<=t; j++)
    {
        for(i=1; i<=6; i++)
            scanf("%d",&v[i]);
        scanf("%d",&n);
        ok=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&sum);
            for(d=6; d>=1; d--)
            {
                if(v[d]>sum/cost[d])
                    nr=sum/cost[d];
                else
                    nr=v[d];
                sum=sum-nr*cost[d];
                v[d]=v[d]-nr;
            }
            if(sum>0)
                ok=1;
        }
        if(ok==1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}