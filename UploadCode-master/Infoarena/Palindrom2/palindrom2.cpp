#include <cstdio>
#include <cstring>
using namespace std;
char s[1005];
int n;
bool pali(int k)
{
    int i = k,j = n-1;
    while(i < j)
    {
        if(s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
int main()
{
    freopen("palindrom2.in","r",stdin);
    freopen("palindrom2.out","w",stdout);
    int i,j;
    gets(s);
    n=strlen(s);
    for(i=0;i<n;++i)
        if(pali(i))
        {
        printf("%s",s);
        for(j=i-1;j>=0;--j)
            printf("%c",s[j]);
        return 0;
        }
    printf("%s",s);
    for(j=n-1;j>=0;--j)
        printf("%c",s[j]);
    return 0;
}