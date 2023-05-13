#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[1000005];
int main()
{
    gets(s);
    int nrm=0,ans=0;
    for(int i=0;i<strlen(s);++i)
    {
        if(s[i]=='M')
            nrm++;
        else
            if(nrm>0) ans=max(ans+1,nrm);
    }
    printf("%d",ans);
    return 0;
}