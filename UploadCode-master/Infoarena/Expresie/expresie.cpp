#include <cstdio>
using namespace std;
int v[1005];
int main()
{
    freopen("expresie.in","r",stdin);
    freopen("expresie.out","w",stdout);
    int n,i,j;
    long long int s=0,maxs=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        {scanf("%d",&v[i]);
        s+=v[i];}
    for(i=1;i<=n-2;++i)
        for(j=i+1;j<=n-1;++j)
        {
            long long int temp_s;
            if(j==i+1)
            {
                temp_s=s-v[i]-v[i+1]-v[i+2];
                temp_s+=((long long int)((long long int)v[i]*v[i+1])*v[i+2]);
            }
            else
            {
                temp_s=s-v[i]-v[i+1]-v[j]-v[j+1];
                temp_s=temp_s+(long long int)v[i]*v[i+1]+(long long int)v[j]*v[j+1];
            }
            if(temp_s>maxs)
                maxs=temp_s;
        }
    printf("%lld",maxs);
    return 0;
}