#include<cstdio>
long long p,q,a,b,x,y,z,fac[1<<18];
void eucl(long long a,long long b,long long &x,long long &y,long long &d)
{
    if(b==0)
    {
		x=1;
		y=0;
		d=a;
		return;
	}
	long long x1,y1;
	eucl(b,a%b,x1,y1,d);
	x=y1;
	y=x1-(a/b)*y1;
}
long long getfact(long long n,long long pr)
{
	long long rez=0;
	while(n>=pr)
	{
		rez+=n/pr;
		n/=pr;
	}
	return rez;
}
long long inversmod(long long a)
{
	long long x,y,d;
	x=y=d=0;
	eucl(a,p,x,y,d);
	if(x>0)
		return x%p;
	return p+x%p;
}
long long comb(long long a,long long b)
{
	long long put=1,rez=1;
	while(put<=a/p)
		put*=p;
	for(;put;put/=p)
	{
		long long m=a/put,n=b/put;
		a-=m*put;
		b-=n*put;
		rez=rez*(((fac[m]*inversmod(fac[n]))%p)*inversmod(fac[m-n]))%p;
	}
	return rez;
}
void rezolv(long long a,long long b)
{
	long long prod=0;
	prod=comb(a,b);
	printf("%lld\n",prod);
}
void pregen(long long pr)
{
	fac[0]=1;
	for(long long i=1;i<pr;i++)
		fac[i]=(fac[i-1]*i)%pr;
}
int main()
{
    freopen("jap2.in","r",stdin);
    freopen("jap2.out","w",stdout);
	scanf("%lld%lld",&p,&q);
	pregen(p);
	for(long long i=1;i<=q;++i)
	{
		scanf("%lld%lld",&a,&b);
		x=getfact(a,p);
		y=getfact(b,p);
		z=getfact(a-b,p);
		if(x==y+z)
		{
			rezolv(a,b);
		}
		else printf("0\n");
	}
    return 0;
}