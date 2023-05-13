#include <bits/stdc++.h>
using namespace std;
int main()
{
    //    freopen("cocochanel.in","r",stdin);
    //    freopen("cocochanel.out","w",stdout);
    int a,b,d,cnt=0;
    scanf("%d%d",&a,&b);
    a-=b;
    if(a==0)
    {
        printf("infinity");
        return 0;
    }
    if(a<0)
    {
        printf("0");
        return 0;
    }
    for(d=1;d<=sqrt(a);++d)
    {
        if(a%d==0 && a/d==d)
        {
            if(a/d>b)
                cnt++;
        }
        if(a%d==0 && a/d!=d)
        {
            if(d>b)
                cnt++;
            if(a/d>b)
                cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}