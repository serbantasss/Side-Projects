#include <cstdio>

using namespace std;

int main()
{
    freopen("cristale.in","r",stdin);
    freopen("cristale.out","w",stdout);
    char c1,c2,c3,c;
    int n,q,i,n1,n2,n3;
    scanf("%c %c %c\n",&c1,&c2,&c3);
    scanf("%d",&q);
    for(;q;--q)
    {
        scanf("%d ",&n);
        n1=n2=n3=0;
        for(i=1;i<=n;++i)
        {
            scanf("%c",&c);
            if(c==c1)
                n1++;
            if(c==c2)
                n2++;
            if(c==c3)
                n3++;
        }
        if(n1==n || n2==n || n3==n)
        {
            printf("%d\n",n);
            continue;
        }
        if(n1%2==n2%2 && n2%2==n3%2)
            {
                printf("%d\n",2);
                continue;
            }
        printf("1\n");
    }
    return 0;
}