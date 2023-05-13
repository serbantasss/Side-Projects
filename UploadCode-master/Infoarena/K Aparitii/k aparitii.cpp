#include <cstdio>

using namespace std;
int a[15][15];
int main()
{
		freopen("aparitii.in","r",stdin);
		freopen("aparitii.out","w",stdout);
		int n,i,j,k,x,p;
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&x);
			p=0;
			do
			{
				a[p][x%10]++;
				p++;
				x/=10;
			}while(x);
		}
		int nr=0;
		for(i=9;i>=0;--i)
		{
			for(j=0;j<=9;++j)
				if(a[i][j]%k!=0)
					nr=nr*10+j;
		}
		printf("%d",nr);
    return 0;
}