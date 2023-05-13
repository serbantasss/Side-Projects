#include <cstdio>
using namespace std;
int max(int x,int y)
{
    if(x>y)
        return x;
    return y;
}
int plm(int x,int ma)
{
    if(x>=ma)
        return 0;
    return ma-x+1;
}
int plm2(int x,int ma)
{
    if(x>ma)
        return 0;
    return ma-x+1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,ma,nr=0;
        scanf("%d%d%d",&a,&b,&c);
        ma=max(a,max(b,c));
        if(a==ma)
            nr++;
        if(b==ma)
            nr++;
        if(c==ma)
            nr++;
        if(nr==1)
            printf("%d %d %d\n",plm(a,ma),plm(b,ma),plm(c,ma));
        else
        {
            printf("%d %d %d\n",plm2(a,ma),plm2(b,ma),plm2(c,ma));
        }
    }
    return 0;
}