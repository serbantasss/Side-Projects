//cojoegay
#include<bits/stdc++.h>
using namespace std;
int mat[505][505],k;
void build(int st,int sus,int jos,int dr)
{
    if(st>dr || sus>jos)
        return;
    k++;
    int p=1;
    for(;p*2<=dr-st+1 && p*2<=jos-sus+1;p=p*2);
    for(int i=sus;i<=sus+p-1;++i)
        for(int j=st;j<=st+p-1;++j)
            mat[i][j]=k;
    build(st,sus+p,jos,st+p-1);
    build(st+p,sus,jos,dr);
}
int main()
{
    freopen("piese.in","r",stdin);
    freopen("piese.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,1,n,m);
    printf("%d\n",k);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    return 0;
}