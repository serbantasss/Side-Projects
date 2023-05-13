#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int sp[1000005],v[1000005];
char s[1000005];
int main()
{
    int n,i,j,t=0,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    scanf("\n");
    gets(s);
    sp[0]=v[0];
    for(i=1;i<n;i++)
        sp[i]=sp[i-1]+v[i];
    for(i=0;i<n;i++)
        if(s[i]=='1')
            t+=v[i];
 
    ans=t;
    t=0;
    for(i=n-1;i>0;i--)
    {
        if(s[i]=='1')
        {
            ans=max(ans,sp[i-1]+t);
            t+=v[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}