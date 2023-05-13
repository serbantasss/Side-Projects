#include <cstdio>
using namespace std;
 
int main()
{
    int n,i,ok=0;
    scanf("%d\n",&n);
    char ch1,ch2;
    scanf("%c",&ch1);
    for(i=2;i<=n;++i)
    {
        scanf("%c",&ch2);
        if(ch1!=ch2 && ok==0)
            printf("YES\n%c%c",ch1,ch2),ok=1;
        ch1=ch2;
    }
    if(!ok)
        printf("NO");
    return 0;
}