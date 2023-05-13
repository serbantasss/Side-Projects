#include <cstdio>
 
using namespace std;
int v[100005],nr[4];
///int dx[]={0,0,1,-1};
///int dy[]={-1,1,0,0};
bool verif()
{
    return nr[0]>0 || nr[1]>0 || nr[2]>0 || nr[3]>0;
}
int main()
{
    int t,sx,sy,fx,fy,pas=0;
    scanf("%d%d%d%d%d\n",&t,&sx,&sy,&fx,&fy);
    if(sx<fx)
        nr[2]+=fx-sx;
    if(sx>fx)
        nr[3]+=sx-fx;
    if(sy<fy)
        nr[1]+=fy-sy;
    if(sy>fy)
        nr[0]+=sy-fy;
    for(int i=1;i<=t;i++)
    {
        char ch;
        scanf("%c",&ch);
        if(ch=='S')
            nr[0]--;
        if(ch=='N')
            nr[1]--;
        if(ch=='W')
            nr[3]--;
        if(ch=='E')
            nr[2]--;
        if(!verif() && !pas)
            pas=i;
    }
    if(!pas)
        printf("-1");
    else
        printf("%d",pas);
    return 0;
}