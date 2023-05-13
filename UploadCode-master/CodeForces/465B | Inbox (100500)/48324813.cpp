#include <cstdio>
 
using namespace std;
int v[1005];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d",&v[i]);
    int view=0,op=0;
    for(i=1;i<=n;++i)
    {
        if(v[i]==1)
        {
            if(view==0)
                view=1;
            op++;
        }
        else
        {
            if(view==1)
                op++,view=0;
        }
 
    }
    if(op==0)
        printf("%d",0);
    else
        if(v[n]==1)
            printf("%d",op);
    else
        printf("%d",op-1);
    return 0;
}