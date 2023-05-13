#include<cstdio>
#include<fstream>
#include<algorithm>
using namespace std;
FILE *f=fopen("sotron.in","r");
ofstream g("sotron.out");
int a[250][250],b[250][250];
int main()
{
    int n,i,j,sol=0;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        fscanf(f,"%d",&a[i][j]);
    for(i=n;i>=1;i--)
    for(j=1;j<=n;j++)
    {
        if((i+j)%2==1)
            b[i][j]=max(0,b[i+1][j])+a[i][j];
        else
            b[i][j]=max(0,b[i][j-1])+a[i][j];
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        sol=max(sol,b[i][j]);
    g<<sol;
    return 0;
}