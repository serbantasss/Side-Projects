#include<cstdio>
using namespace std;
long int sol[19]= {0,1,1,0,2,0,2,0,4,0,96,0,1024,0,2880,0,81024,0,770144};
int main()
{
    freopen("inel.in","r",stdin);
    freopen("inel.out","w",stdout);
    int n;
    scanf("%d",&n);
    printf("%d",sol[n]);
    return 0;
}