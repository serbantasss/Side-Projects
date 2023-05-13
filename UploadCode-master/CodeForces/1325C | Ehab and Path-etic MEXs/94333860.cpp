#include <cstdio>
#include <algorithm>
#include <vector>
#define x first
#define y second
using namespace std;
pair<int,int> ed[100005];
int fii[100005],o[100005];
int main()
{
    int n,nrfr=0;
    scanf("%d",&n);
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&ed[i].x,&ed[i].y);
        fii[ed[i].x]++;
        fii[ed[i].y]++;
    }
    if(n==2)
    {
        printf("0\n");
        return 0;
    }
    for(int i=1;i<n;++i)
    {
        if(fii[ed[i].x]==1)
        {
            nrfr++;
            o[i]=nrfr;
        }
        if(fii[ed[i].y]==1)
        {
            nrfr++;
            o[i]=nrfr;
        }
    }
    if(nrfr==2)
        for(int i=1;i<n;++i)
            printf("%d\n",i-1);
    else
    {
        for(int i=1;i<n;++i)
        if(o[i]==0)
        {
            nrfr++;
            o[i]=nrfr;
        }
        for(int i=1;i<n;++i)
            printf("%d\n",o[i]-1);
    }
    return 0;
}