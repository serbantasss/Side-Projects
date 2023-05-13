#include <cstdio>
#include <algorithm>
#include <vector>
#define x first
#define y second
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k=n,p;
        scanf("%d",&n);
        p=n;
        vector<int>v(n+1);
        vector<int>maxk(n+1);
        vector<int>afis;
        maxk[0]=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&v[i]);
            maxk[i]=maxk[i-1];
            if(maxk[i]<v[i])
                maxk[i]=v[i];
        }
        for(int i=n;i>=1;--i)
            if(v[i]==maxk[i])
            {
                for(int j=i;j<=p;++j)
                    afis.push_back(v[j]);
                p=i-1;
            }
        for(int i=0;i<n;++i)
            printf("%d ",afis[i]);
        printf("\n");
    }
    return 0;
}