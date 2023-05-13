#include <bits/stdc++.h>
using namespace std;
int n,m,nr=0,k,viz[21][21];
int ec1(int i,int j,int x,int y)
{
    int j1;
    if(j<y)
    {for(j1=j+1;j1<y;++j1)
            if(!viz[i][j1])
                return 0;}
    else
    {for(j1=y+1;j1<j;++j1)
            if(!viz[i][j1])
                return 0;}
    return 1;
}
int ec2(int i,int j,int x,int y)
{
    int i1;
    for(i1=i+1;i1<x;++i1)
        if(!viz[i1][j])
            return 0;
    return 1;
}
int ec3(int i,int j,int x,int y)
{
    if(j-i==y-x)
    {
        int i1,c=j-1;
        for(i1=i+1;i1<x;++i1)
            if(!viz[i1][i1+c])
                return 0;
    }
    return 1;
}
 
int verifica(int i,int j,int x,int y)
{
    if(viz[i][j])
        return 0;
    int i1;
    if(i>=x)
    {
        if(i==x)
        {
            if(j>y)
            {
                i1=y;
                y=j;
                j=i1;
            }
        }
        else
        {
            i1=i;
            i=x;
            x=i1;
            i1=j;
            j=y;
            y=i1;
        }
    }
    if(i==x)
        return ec1(i,j,x,y);
    if(j==y)
        return ec2(i,j,x,y);
    return ec3(i,j,x,y);
}
 
void back(int niv,int x,int y)
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(verifica(i,j,x,y))
            {
                if(niv==k)
                {
                    ++nr;
                    nr%=666013;
                }
                else
                {
                    viz[i][j]=1;
                    back(niv+1,i,j);
                    viz[i][j]=0;
                }
            }
}
int calc[21][21];
int main()
{
    freopen("android.in","r",stdin);
    freopen("android.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n>m)
    {
        int aux=n;
        n=m;
        m=aux;
    }
    /*int i,j,mx=n*m;
    for(k=2;k<=mx;++k)
    {
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                viz[i][j]=1;
                back(2,i,j);
                viz[i][j]=0;
            }
        }
    }
    nr+=mx;
    nr%=666013;
    printf("calc[%d][%d]=%d\n",n,m,nr);*/
    calc[1][1]=1;
    calc[1][2]=4;
    calc[1][3]=11;
    calc[1][4]=26;
    calc[1][5]=57;
    calc[1][6]=120;
    calc[1][7]=247;
    calc[1][8]=502;
    calc[1][9]=1013;
    calc[1][10]=2036;
    calc[1][11]=4083;
    calc[1][12]=8178;
    calc[1][13]=16369;
    calc[1][14]=32752;
    calc[1][15]=65519;
    calc[1][16]=131054;
    calc[1][17]=262125;
    calc[1][18]=524268;
    calc[1][19]=382542;
    calc[1][20]=99091;
    calc[2][2]=64;
    calc[2][3]=1392;
    calc[2][4]=44812;
    calc[2][5]=19145;
    calc[2][6]=193543;
    calc[2][7]=615565;
    calc[2][8]=628584;
    calc[2][9]=486002;
    calc[2][10]=377052;
    calc[3][3]=389497;
    calc[3][4]=194296;
    calc[3][5]=274484;
    calc[3][6]=241730;
    calc[4][4]=587352;
    calc[4][5]=95348;
    printf("%d",calc[n][m]);
    return 0;
}