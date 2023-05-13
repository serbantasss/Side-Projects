#include<stdio.h>
#define mod 9973
#include<bitset>
#define ll long long
using namespace std;
int  pr[1000000],t;
struct nod
{
	ll nr,p;
}d[1000000];
bitset<1000100> c;
ll put(ll x)
{
	return x*x;
}
ll invmod(ll a,ll b)
{
	if(b==1) return a%mod;
	else if(b%2==1) return ( put( invmod(a, (b-1)/2 )) %mod *a%mod)%mod;
	return (put(invmod(a,b/2)))%mod;
}
void prelucreaza()
{
	ll n=0;
	int i=0,nd=1,sd=1;
	scanf("%lld",&n);
	for(i=1;pr[i]*pr[i]<=n;++i)
	{
		int nr=0,s=1;
		while(n%pr[i]==0)
		{
			n/=pr[i];
			s*=pr[i];
			nr++;
		}
		if(nr)
		{
			nd*=(nr+1);
			sd*=((1LL*pr[i]*s-1)%mod);
			sd%=mod;
			sd*=invmod(pr[i]-1,mod-2);
			sd%=mod;
		}
	}
	if(n>1)
	{
		nd*=2;
		sd*=((1LL*n*n-1)%mod);
		sd%=mod;
		sd*=invmod(n-1,mod-2);
		sd%=mod;
	}
	printf("%d %d\n",nd,sd);
}
int main()
{
	freopen("ssnd.in","r",stdin);
	freopen("ssnd.out","w",stdout);
	scanf("%d",&t);
	for(int i=2;i<=1000000;++i)
		if(!c[i])
		{
			pr[++pr[0]]=i;
			for(int j=i+i;j<=1000000;j+=i)c[j]=1;
		}
	for(int i=1;i<=t;++i)
		prelucreaza();
	return 0;
}