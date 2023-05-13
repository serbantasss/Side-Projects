#include <bits/stdc++.h>
using namespace std;
int f[30];
char s[30];
int main()
{
    int n,i,x,y,ans=0;
    char ch;
    scanf("%d\n",&n);
    for(i=1;i<=n;++i)
    {
        gets(s);
        f[s[0]-'a'+1]++;
    }
    for(i=1;i<=26;++i)
        if(f[i]>2)
            if(f[i]%2==1)
            {
                x=f[i]/2;
                y=f[i]/2+1;
                ans+=x*(x-1)/2+y*(y-1)/2;
            }
            else
            {
                x=f[i]/2;
                ans+=x*(x-1);
            }
    printf("%d",ans);
    return 0;
}