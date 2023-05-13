#include <cstdio>
#include <algorithm>
using namespace std;
int c[16005], s[16005], s1[16005], s0[16005], q1[16005], q0[16005], sol[16005];
int main()
{
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	int i, st1, st0, dr1, dr0, q, k, t, n;
	scanf("%d",&n);
	for (i=1; i<=n; i++)
        scanf("%d %d",&c[i],&s[i]);
	for (i=n; i>=0; i--)
	{
		s1[i]=s1[i+1];
		s0[i]=s0[i+1];
		if (c[i+1])
            s1[i]+=s[i+1];
        else
            s0[i]+=s[i+1];
	}
	scanf("%d",&q);
	for(;q;--q)
	{
		scanf("%d %d",&k,&t);
		st1=st0=1;
		dr1=dr0=1;
		q0[1]=0;
		q1[1]=0;
		for (i=1; i<=n; i++)
		{
			while (q0[st0]+k<i && st0<=dr0) st0++;
			while (q1[st1]+k<i && st1<=dr1) st1++;
			sol[i]=min(sol[q0[st0]]+s0[q0[st0]]-s0[i], sol[q1[st1]]+s1[q1[st1]]-s1[i])+t;
			while (sol[q0[dr0]]+s0[q0[dr0]]>=sol[i]+s0[i] && st0<=dr0) dr0--;
			while (sol[q1[dr1]]+s1[q1[dr1]]>=sol[i]+s1[i] && st1<=dr1) dr1--;
			q0[++dr0]=i;
			q1[++dr1]=i;
		}
		printf("%d\n",sol[n]);
	}
	return 0;
}