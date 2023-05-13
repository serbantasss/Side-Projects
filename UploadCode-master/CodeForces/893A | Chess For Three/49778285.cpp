#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j1,j2,p,x;
    scanf("%d",&n);
    j1=1;
    j2=2;
    p=3;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        if(x==j1)
        {
            x=j2;
            j2=p;
            p=x;
            continue;
        }
        if(x==j2)
        {
            x=j1;
            j1=j2;
            j2=x;
            x=j2;
            j2=p;
            p=x;
            continue;
        }
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}