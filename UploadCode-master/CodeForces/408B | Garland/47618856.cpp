#include <bits/stdc++.h>
using namespace std;
char s[1005];
int f1[30],f2[30];
int main()
{
    int n,i,j,lung=0;
    gets(s);
    n=strlen(s);
    for(i=0; i<n; ++i)
        f1[s[i]-'a']++;
    gets(s);
    n=strlen(s);
    for(i=0; i<n; ++i)
        f2[s[i]-'a']++;
    for(i=0; i<=26; ++i)
    {
        if(f1[i]==0)
        {
            if(f2[i]==0)
                continue;
            else
            {
                printf("-1");
                return 0;
            }
        }
        else
        {
            if(f1[i]<=f2[i])
                lung+=f1[i];
            else
                lung+=f2[i];
        }
        }
    cout<<lung;
    return 0;
}