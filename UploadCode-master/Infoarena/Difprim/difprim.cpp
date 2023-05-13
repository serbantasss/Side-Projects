#include <bits/stdc++.h>
using namespace std;
bitset<10000005> ciur;
int main()
{
    freopen("difprim.in","r",stdin);
    freopen("difprim.out","w",stdout);
    int a,b,i,j,x,y,ma=-1;
    scanf("%d%d",&a,&b);
    if(a==b)
    {
        printf("-1");
        return 0;
    }
    if(a==1 || a==2)
    {
        if(b==2)
        {
            printf("-1");
            return 0;
        }
        if(b==3 || b==4)
        {
            printf("2 3");
            return 0;
        }
    }
    ciur[0]=ciur[1]=1;
    int sq=(int)sqrt((double)b);
    for(i=3; i<=sq; i+=2)
        if(!ciur[i])
        {
            for(j=i*i; j<=b; j+=2*i)
                ciur[j]=1;
        }
    bool ok=1;
    for(i=a+(a%2+1)%2; i<=b; i+=2)
        if(ciur[i]==0)
        {
            if(ok)
            {
                ok=0,x=i;
                continue;
            }
            else
            {
                if(i-x>ma)
                    ma=i-x,y=i;
                x=i;
            }
        }
    if(ma==-1)
        printf("-1");
    else
        printf("%d %d",y-ma,y);
    return 0;
}