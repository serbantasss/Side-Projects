#include <bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("cabana.in","r",stdin);
//    freopen("cabana.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==b)
            printf("0\n");
        if(a<b)
        {
            if((b-a)%2==0)
                printf("2\n");
            else
                printf("1\n");
        }
        if(a>b)
        {
            if((a-b)%2==0)
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return 0;
}