#include <bits/stdc++.h>
#define INF 1LL<<40
typedef long long LL;
using namespace std;
struct cojo{
int last,nr=0;
};
cojo st[105];
bool mycmp(int a,int b)
{
    return a>b;
}
int v[105];
int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    sort(v+1,v+n+1);
    int p=0;
    for(i=1;i<=n;i++)
    {
     int ok = 0;
     for(j=1;j<=p;j++)
     {
         if(v[i]>=st[j].nr)
         {
             st[j].nr++;
             ok=1;
             break;
         }
     }
     if(ok==0)
     {
         p++;
         st[p].nr=1;
     }
    }
    printf("%d",p);
    return 0;
}