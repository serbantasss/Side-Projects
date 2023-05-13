#include <cstdio>
using namespace std;
int lin[105],col[105];
int main()
{
    int n,m,i,j;
    char ch;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("\n");
        for(j=1; j<=n; ++j)
        {
            scanf("%c",&ch);
            if(ch=='.')
            {
                if(!lin[i])
                    lin[i]=j;
                if(!col[j])
                    col[j]=i;
            }
        }
    }
    int ok=1;
    for(i=1; i<=n; ++i)
        if(lin[i]==0)
            ok=0;
    if(ok)
    {
        for(i=1; i<=n; ++i)
            printf("%d %d\n",i,lin[i]);
        return 0;
    }
    int steag=1;
    for(i=1; i<=n; ++i)
        if(col[i]==0)
            steag=0;
    if(steag)
    {
        for(i=1; i<=n; ++i)
            printf("%d %d\n",col[i],i);
        return 0;
    }
    printf("-1");
    return 0;
}