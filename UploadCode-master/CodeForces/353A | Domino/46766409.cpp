#include <bits/stdc++.h>
 
using namespace std;
int v[200];
int main()
{
    int n,k=0,i,s1=0,s2=0,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&x,&y);
        s1+=x;
        s2+=y;
        if(x%2!=y%2)
          k=1;
    }
    if(s1%2!=s2%2)
        printf("-1");
    else
        if(s1%2==1 && k==1)
            printf("1");
        else
            if(s1%2==0)
                printf("0");
            else
                printf("-1");
    return 0;
}