#include <cstdio>
using namespace std;
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    freopen("cmmdc.in","r",stdin);
    freopen("cmmdc.out","w",stdout);
    int a,b,s;
    scanf("%d%d",&a,&b);
    s=euclid(a,b);
    if(s!=1)
       printf("%d",s);
    else
        printf("0");
    return 0;
}