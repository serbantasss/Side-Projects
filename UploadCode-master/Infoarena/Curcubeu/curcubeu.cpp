#include <fstream>
using namespace std;
const int nmax=1000001;
unsigned int a[1000001],b[1000001],c[1000001],sol[1000001],oc[1000001];
int main()
{
	ifstream in("curcubeu.in");
    ofstream out("curcubeu.out");
	int n;
	in>>n>>a[1]>>b[1]>>c[1];
	oc[1]=1;
	for(int i=2;i<n;i++)
	{
		a[i]=(1LL*a[i-1]*i)%n;
		b[i]=(1LL*b[i-1]*i)%n;
		c[i]=(1LL*c[i-1]*i)%n;
		oc[i]=i;
	}
	for(int i=n-1;i>=1;i--)
	{
		int st=min(a[i],b[i]);
		int nd=max(a[i],b[i]);
		int ns=st;
		while(ns <= nd)
		{
			if(oc[ns]==ns)
			{
				sol[ns]=c[i];
				oc[ns]=nd+1;
				ns++;
			}
			else
			{
				int aux=oc[ns];
				oc[ns]=nd+1;
				ns=aux;
			}
		}
	}
	for(int i=1;i<n;i++)
		out<<sol[i]<<"\n";
    return 0;
}