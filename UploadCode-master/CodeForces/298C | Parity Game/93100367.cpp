#include <cstdio>
#include <cstring>
using namespace std;
char s1[1005],s2[1005];
int main()
{
    int n1=0,n2=0,l1,l2;
    char ch;
    gets(s1);
    l1=strlen(s1);
    gets(s2);
    l2=strlen(s2);
    for(int i=0; i<l1; i++)
        if(s1[i]=='1')
            n1++;
    for(int i=0; i<l2; i++)
        if(s2[i]=='1')
            n2++;
    if(n1+n1%2>=n2)
        printf("YES");
    else
        printf("NO");
    return 0;
}