#include <cstdio>
#include <cstring>
using namespace std;
char ch1[500],ch2[500],ch3[500];
int main()
{
    freopen("entropy.in","r",stdin);
    freopen("entropy.out","w",stdout);
    int t,i,j,a,b,c;
    char ch;
    scanf("%d\n",&t);
    for(;t;--t)
    {
        scanf("%s%s%s",&ch1,&ch2,&ch3);
        a=strlen(ch1);
        b=strlen(ch2);
        c=strlen(ch3);
        for(i=1;i<=b;++i)
            printf("o");
        for(i=b-1;i>=0;--i)
            ch1[a++]=ch2[i];
        b=0;
        for(i=1;i<=c;++i)
            printf("q");
        for(i=c-1;i>=0;--i)
            ch1[a++]=ch3[i];
        c=0;
        for(i=a-1;i>=0;--i)
            if(ch1[i]=='b')
            {
                printf("m");
            }
            else
            {
                ch3[c++]=ch1[i];
                printf("n");
            }
        a=0;
        int cb=0;
        for(i=c-1;i>=0;--i)
            if(ch3[i]=='a')
            {
            printf("q");
            }
            else
            {
                cb++;
                printf("r");
            }
        for(;cb;--cb)
            printf("p");
        printf("\n");
    }
    return 0;
}