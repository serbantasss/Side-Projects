#include <cstdio>
using namespace std;
const int nmax=16000;
int v[nmax+5];
int main()
{
    freopen("transport.in","r",stdin);
    freopen("transport.out","w",stdout);
    int n,k,i,s;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&v[i]);
        s+=v[i];
    }
    int st,dr,mid,c,tr,sum,last;
    st=1;
    dr=s;
    while(st<=dr)
    {
        mid=st+dr;
        mid/=2;
        c=mid;
        tr=0;
        sum=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]>c)
            {
                tr=k+1;
                sum=0;
                break;
            }
            if(sum+v[i]>c)
            {
                tr++;
                sum=v[i];
            }
            else
                sum+=v[i];
        }
        if(sum>0)
            tr++;
        if(tr<=k)
        {
            last=mid;
            dr=mid-1;
        }
        else
        {
            st=mid+1;
        }
    }
    printf("%d",last);
    return 0;
}