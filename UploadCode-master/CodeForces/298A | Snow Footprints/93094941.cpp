#include <cstdio>
 
using namespace std;
char s[1005];
int main()
{
    int n,i,fr=-1,fl=-1,lr,ll;
    scanf("%d\n",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%c",&s[i]);
        if(fr==-1 && s[i]=='R')
            fr=i;
        if(fl==-1 && s[i]=='L')
            fl=i;
        if(s[i]=='R')
            lr=i;
        if(s[i]=='L')
            ll=i;
    }
    if(fr==-1)
    {
        printf("%d %d",ll,fl-1);
        return 0;
    }
    if(fl==-1)
    {
        printf("%d %d",fr,lr+1);
        return 0;
    }
    printf("%d %d",fr,fl-1);
    return 0;
}