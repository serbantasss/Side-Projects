#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
long long int cost[30];
char s[1000005];
int main()
{
    freopen("texttrim.in","r",stdin);
    freopen("texttrim.out","w",stdout);
    for(long long int  i=0;i<=26;++i)
        scanf("%lld\n",&cost[i]);
    scanf("%[^\n]",s);
    long long int w,n,i,c=0;
    scanf("%lld",&w);
    n=strlen(s);
    for(i=0;i<n;++i)
    {
        if(s[i]==' ')
            c+=cost[0];
        else
            c+=cost[s[i]-'a'+1];
    }
    if(w>=c)
        {
            for(i=0;i<n;++i)
                printf("%c",s[i]);
        //printf("...");
        }
    else
    {
        w=w-c-3;
        n--;
        while(w<0)
        {
            if(s[n]==' ')
                w+=cost[0];
            else
                w+=cost[s[n]-'a'+1];
            n--;
        }
        for(i=0;i<=n;++i)
            printf("%c",s[i]);
        printf("...");
    }
    return 0;
}