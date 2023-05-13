#include<bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    int t,h,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&h,&n);
        int res = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&v[i]);
        }
        v[n]=0;
        for(int i=1; i<n; i++)
        {
            if(v[i]==(v[i+1]+1))
            {
                i++;
            }
            else
            {
                res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}