#include <bits/stdc++.h>
using namespace std;
int cp[300005],p2[20];
int main()
{
    int n,q,ok=0;//0-or 1-xor
    scanf("%d%d",&n,&q);
    p2[0]=1;
    for(int i=1;i<=n;++i)
        p2[i]=p2[i-1]*2;
    for(int i=1;i<=p2[n];++i)
        scanf("%d",&cp[i+p2[n]-1]);
    for(int p=n-1;p>=0;--p)
    {
        if(!ok)
            for(int i=1,j=1;i<=p2[p];++i,j+=2)
                cp[i+p2[p]-1]=((cp[j+p2[p+1]-1]) | (cp[j+p2[p+1]]));
        else
            for(int i=1,j=1;i<=p2[p];++i,j+=2)
                cp[i+p2[p]-1]=((cp[j+p2[p+1]-1]) ^ (cp[j+p2[p+1]]));
        ok=(ok+1)%2;
    }
    while(q--)
    {
        int x,y,b;
        scanf("%d%d",&x,&b);
        cp[x+p2[n]-1]=b;
        ok=0;
        for(int p=n-1;p>=0;--p)
        {
            y=(x+1)/2;
            if(!ok)
                if(x%2==0)
                    cp[y+p2[p]-1]=((cp[x+p2[p+1]-2]) | (cp[x+p2[p+1]-1]));
                else
                    cp[y+p2[p]-1]=((cp[x+p2[p+1]-1]) | (cp[x+p2[p+1]]));
            else
                if(x%2==0)
                    cp[y+p2[p]-1]=((cp[x+p2[p+1]-2]) ^ (cp[x+p2[p+1]-1]));
                else
                    cp[y+p2[p]-1]=((cp[x+p2[p+1]-1]) ^ (cp[x+p2[p+1]]));
            x=y;
            ok=(ok+1)%2;
        }
        printf("%d ",cp[1]);
    }
    return 0;
}