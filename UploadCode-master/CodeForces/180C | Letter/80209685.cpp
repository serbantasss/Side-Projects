#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
char s[100005];
int st[100005],dr[100005];
int main()
{
    int n,ans;
    gets(s);
    n=strlen(s);
    for(int i=1;i<n;++i)
        if(islower(s[i-1]))
            st[i]=st[i-1]+1;
        else
            st[i]=st[i-1];
    for(int i=n-2;i>=0;--i)
        if(isupper(s[i+1]))
            dr[i]=dr[i+1]+1;
        else
            dr[i]=dr[i+1];
    ans=n;
    for(int i=0;i<n;++i)
        if(ans>st[i]+dr[i])
            ans=st[i]+dr[i];
    printf("%d",ans);
    return 0;
}