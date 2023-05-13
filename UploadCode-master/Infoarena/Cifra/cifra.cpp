#include <cstdio>
#include <cstring>
using namespace std;
const int nmax=100;
int v[nmax+5];
char s[101];
int main() {
    int i,p,x,y;
    for(i=1; i<=nmax; ++i) 
		{
        x=i%10;
        y=i%4;
        if(y==0)
            y=4;
				p=1;
				for(;y;--y)
					p=p*x;
				v[i]=(v[i-1]+p%10)%10;
    }
    freopen("cifra.in","r",stdin);
    freopen("cifra.out","w",stdout);
    int t,l;
    scanf("%d\n",&t);
    for(i=1;i<=t;++i)
		{
			int nr=0;
			gets(s);
			scanf("\n");
			l=strlen(s);
			if(l==1)
				printf("%d\n",v[s[l-1]-'0']);
			else
			{
				nr=(s[l-2]-'0')*10+s[l-1]-'0';
				printf("%d\n",v[nr]);
			}
		}
    return 0;
}