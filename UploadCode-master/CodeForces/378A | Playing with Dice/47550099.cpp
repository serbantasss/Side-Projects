#include <cstdio>
#include <cstdlib>
using namespace std;
int a,b,i,nr1,nr2,nr3;
int main()
{
    scanf("%d%d",&a,&b);
    for(i=1;i<=6;++i)
        if(abs(i-a)<abs(i-b))
            nr1++;
        else
            if(abs(i-a)==abs(i-b))
                nr2++;
            else
                nr3++;
    printf("%d %d %d",nr1,nr2,nr3);
    return 0;
}