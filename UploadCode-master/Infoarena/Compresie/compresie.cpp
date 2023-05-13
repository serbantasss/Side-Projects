#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
using namespace std;
char mat[1005][1005],s[1000005];
int pointer;
void build(int x1,int y1,int x2,int y2)
{
    if(x1>x2 || y1>y2)
        return;
    if(s[pointer]=='*')
    {
        pointer++;
        int x=(x1+x2)/2,y=(y1+y2)/2;
        build(x1,y1,x,y);
        build(x1,y+1,x,y2);
        build(x+1,y1,x2,y);
        build(x+1,y+1,x2,y2);
    }
    else
    {
        while(isdigit(s[pointer]))
            pointer++;
        for(int i=x1; i<=x2; ++i)
            for(int j=y1; j<=y2; ++j)
                mat[i][j]=s[pointer];
        pointer++;
    }
}
int main()
{
    freopen("compresie.in","r",stdin);
    freopen("compresie.out","w",stdout);
    int n=0,i,j,x=0,nr,tait=0,sn;
    scanf("%s",s);
    sn=strlen(s);
    for(i=0; i<sn;)
        if(isdigit(s[i]))
        {
            for(; isdigit(s[i]) && i<sn; x=x*10+s[i]-'0',++i);
            n+=x;
            if(i>=sn)
                break;
        }
        else if(isalpha(s[i]))
        {
            if(x==0)
                n++;
            x=0;
            ++i;
        }
        else
            tait++,++i;
    n=(int)sqrt((double)n);
    printf("%d\n",tait);
    build(1,1,n,n);
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=n; ++j)
            printf("%c",mat[i][j]);
        printf("\n");
    }
    return 0;
}