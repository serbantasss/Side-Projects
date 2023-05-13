#include <cstdio>
#include <string>
using namespace std;
int v[100005];
int main()
{
    int i,j,nr;
    char x,y,a='0',b='#';
    scanf("%c",&a);
    while(scanf("%c",&y))
    {
        if(y=='\n')
            break;
        if(b=='#')
            b=y;
        else
        {
         a=b;
        b=y;
        }
    }
    if(b=='#')
        nr=a-'0';
    else
        nr=(a-'0')*10+b-'0';
    if(b=='#' && nr==0)
    {
        printf("4");
        return 0;
    }
    if(nr%4==0)
    {
        printf("4");
        return 0;
    }
    if(nr%4==1)
    {
        printf("0");
        return 0;
    }
    if(nr%4==2)
    {
        printf("0");
        return 0;
    }
    if(nr%4==3)
    {
        printf("0");
        return 0;
    }
    return 0;
}