#include <bits/stdc++.h>
using namespace std;
bool stari[1<<23];
int put[25];
int main()
{
    freopen("coins.in","r",stdin);
    freopen("coins.out","w",stdout);
    int n,i,ans=0,nr,x,masca;
    scanf("%d",&n);
    put[0]=1;
    for(i=1;i<23;i++)
    {
        put[i]=put[i-1]<<1;
        stari[put[i]-1]=1;
    }
    for(masca=2;masca<put[22];masca++)
    {
        x=-1;
        if(stari[masca])
            continue;
        for(i=0;i<22;i++)
            if(put[i]&masca)
            {
                if (x>=0)
                    stari[masca]|=!stari[masca ^ put[i] ^ put[x]];
            }
            else
                x=i;
    }
    for(i=1;i<=n;++i)
    {
        masca=nr=0;
        for(int j=0;j<22;++j)
        {
            scanf("%d",&x);
            if(x)
            {
                nr++;
                masca+=put[j];
            }
        }
        if(stari[masca])
            ans=ans+nr;
    }
    printf("%d",ans);
    return 0;
}