#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
char s[5005];
int main()
{
    freopen("triopalindrom.in","r",stdin);
    freopen("triopalindrom.out","w",stdout);
    int n,i,j,len,nr=0,potriv;
    scanf("%s",s);
    n=strlen(s);
    for(len=1; len<=n/3; ++len)
    {
        potriv=0;
        for(j=0; j+2*len<n; ++j)
        {
            if(s[j]==s[j+len] && s[j]==s[j+2*len])
                {potriv++;
            if(potriv>=len)
                nr++;}
            else
                potriv=0;
        }
    }
    printf("%d",nr);
    return 0;
}