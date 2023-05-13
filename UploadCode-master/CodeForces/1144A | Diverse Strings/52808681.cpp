#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[10005];
int main()
{
    int n,i,j,len;
    scanf("%d\n",&n);
    for(i=1;i<=n;++i)
    {
        gets(s);
        len=strlen(s);
        sort(s,s+len);
        bool ok=0;
        for(j=0;j<len-1;++j)
            if(s[j]!=char(s[j+1]-1))
                ok=1;
        if(!ok)
            printf("yEs\n");
        else
            printf("nO\n");
    }
    return 0;
}