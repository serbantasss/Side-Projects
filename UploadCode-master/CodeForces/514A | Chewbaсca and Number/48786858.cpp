#include <bits/stdc++.h>
using namespace std;
char s[50];
int main()
{
    int n,i,j;
    gets(s);
    n=strlen(s);
    if(s[0]!='9' && 9-(s[0]-'0')<=(s[0]-'0'))
        s[0]='9'-s[0]+'0';
    for(i=1;i<n;++i)
        if(9-(s[i]-'0')<=(s[i]-'0'))
            s[i]='9'-s[i]+'0';
    for(i=0;i<n;++i)
        printf("%c",s[i]);
    return 0;
}