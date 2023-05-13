#include <cstdio>
 
using namespace std;
int v[100005];
int main()
{
    int n,l,lmax=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&v[i]);
    l=1;
    for(int i=2;i<=n;++i)
        if(v[i]>=v[i-1])
            l++;
        else
        {
            if(l>lmax)
                lmax=l;
            l=1;
        }
    if(l>lmax)
        lmax=l;
    l=1;
    printf("%d",lmax);
    return 0;
}