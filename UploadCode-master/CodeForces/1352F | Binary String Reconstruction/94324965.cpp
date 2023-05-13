#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a>0)
            for(int i=1;i<=a+1;++i)
                printf("0");
        else
            if(b>0)
                b++;
        if(c>0)
            for(int i=1;i<=c+1;++i)
                printf("1");
        else
        {
            b++;
            if(b>0)
                for(int i=1;i<b;++i)
                    if(i%2==1)
                        printf("1");
                    else
                        printf("0");
            printf("\n");
            continue;
        }
        if(b>0)
            for(int i=1;i<b;++i)
                if(i%2==1)
                    printf("0");
                else
                    printf("1");
        printf("\n");
    }
    return 0;
}