#include <cstdio>
using namespace std;
int main()
{
    freopen("fenrir.in","r",stdin);
    freopen("fenrir.out","w",stdout);
    int n=20,i,j;
    //scanf("%d",&n);
    printf("99\n");
    for(i=1;i<=9;++i)
        for(j=0;j<=10;++j)
            printf("%d %d\n",i,j+10);
    return 0;
}