#include <bits/stdc++.h>
 
using namespace std;
int f[17];
int main()
{
    int n,k,k2,bit,i,mask,nr=0;
    scanf("%d%d",&n,&k);
    if(k==1)
        k2=1;
    if(k==2)
        k2=3;
    if(k==3)
        k2=7;
    if(k==4)
        k2=15;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&bit);
        mask=bit;
        if(k>1)
        {
            scanf("%d",&bit);
            mask+=bit*2;
        }
        if(k>2)
        {
            scanf("%d",&bit);
            mask+=bit*4;
        }
        if(k>3)
        {
            scanf("%d",&bit);
            mask+=bit*8;
        }
        if(mask==0)
            nr++;
        if(f[mask]==0)
            f[mask]=1;
    }
    if(nr>0)
        printf("YES");
    else
    {
        bool ok=1;
        for(int mask1=0;mask1<=16 && ok;++mask1)
            for(int mask2=0;mask2<=16 && ok;++mask2)
                if(f[mask1] && f[mask2] && !(mask1&mask2))
                    ok=0;
        if(ok)
            printf("NO");
        else
            printf("YES");
    }
    return 0;
}