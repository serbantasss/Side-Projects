#include <cstdio>
using namespace std;
int main()
{
    char ch;
    int l=0,r=0,u=0,d=0,nrschimb;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='\n')
            break;
        if(ch=='L')
            l++;
        if(ch=='R')
            r++;
        if(ch=='U')
            u++;
        if(ch=='D')
            d++;
    }
    if((l+r+u+d)%2==1)
    {
        printf("-1");
        return 0;
    }
    if(d>u)
    {
        int aux=d;
        d=u;
        u=aux;
    }
    if(l>r)
    {
        int aux=l;
        l=r;
        r=aux;
    }
    r=r-l;
    u=u-d;
    if(r%2==0)
        nrschimb=r/2+u/2;
    else
        nrschimb=(r+u)/2;
    printf("%d",nrschimb);
    return 0;
}