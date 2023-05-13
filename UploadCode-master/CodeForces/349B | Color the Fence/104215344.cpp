#include <bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    int n,m=100009,in;
    scanf("%d",&n);
    for(int i=0;i<9;i++)
    {
        scanf("%d",&a[i]);
        m=min(a[i],m);
    }
    int t=n/m;
    if(t==0)
        printf("-1");
    else
    {
        while(t--)
        {
            for(int i=8;i>=0;i--)
                if((n-a[i])/m==t && a[i]<=n)
                {
                    printf("%d",i+1);
                    n-=a[i];
                }
        }
    }
    return 0;
}