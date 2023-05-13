#include<cstdio>

#include<cstring>
#include<algorithm>
using namespace std;
const int NMAX=25;
int v[NMAX],w[NMAX];

char sir[NMAX];

int cost[]={0,2,5,5,4,5,6,3,7,6};

int n,m,mpower,tcost,best;

bool stop=1;

void compute(int maxt, int i)

{

	int best,j;

	best=2;

	for(j=2;j<=maxt;j++)

		if(((cost[j]<best)||(j>w[i]))&&(cost[j]<=mpower+2))

		{

			best=cost[j];

			w[i]=j;

		}

	mpower=mpower-cost[w[i]]+2;

	if(w[i]<v[i])

		stop=0;

}

int main()

{

	freopen("7segmente.in","r",stdin);

	freopen("7segmente.out","w",stdout);

	scanf("%s %d",sir+1,&mpower);

	n=strlen(sir+1);

	int i;

	for(i=1;i<=n;i++)

	{

		v[i]=sir[i]-'0';

		tcost+=cost[v[i]];

	}

	printf("%d ",tcost);

	m=min(n,mpower/2);

	for(i=1;i<=m;i++)

		w[i]=1;

	mpower-=m*2;

	if(n>m)

		stop=0;

	for(i=1;(i<=m)&&(mpower>-1);i++)

		if(stop)

			compute(v[i],i);

		else

			compute(9,i);

	for(i=1;i<=m;i++)

		printf("%d",w[i]);

	return 0;

}