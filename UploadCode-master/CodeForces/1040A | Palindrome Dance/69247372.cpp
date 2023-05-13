#include <cstdio>
#include <algorithm>
 
using namespace std;
int v[25];
int main()
{
    int n,i,a,b,ok=0,s=0;
    scanf("%d%d%d",&n,&a,&b);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
    }
    for(i=1;i<=(n+1)/2 && !ok;++i)
    {
        if(v[i]==2)
        {
            if(v[n-i+1]==2)
                {
                    if(i==n-i+1)
                        s+=min(a,b);
                    else
                        s+=2*min(a,b);
                    }
            if(v[n-i+1]==1)
                s+=b;
            if(v[n-i+1]==0)
                s+=a;
        }
        if(v[i]==1)
        {
            if(v[n-i+1]==2)
                s+=b;
            if(v[n-i+1]==0)
                ok=1;
        }
        if(v[i]==0)
        {
            if(v[n-i+1]==2)
                s+=a;
            if(v[n-i+1]==1)
                ok=1;
        }
    }
    if(ok==0)
        printf("%d",s);
    else
        printf("-1");
    return 0;
}