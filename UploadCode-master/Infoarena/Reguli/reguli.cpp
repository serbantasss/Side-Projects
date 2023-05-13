#include <bits/stdc++.h>
using namespace std;
int v[500005],regula[500005];
vector<int>dif;
int main()
{
    freopen("reguli.in","r",stdin);
    freopen("reguli.out","w",stdout);
    int n,i,k=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d",&v[i]);
    dif.push_back(0);
    for(i=2;i<=n;++i)
        dif.push_back(v[i]-v[i-1]);
    for(i=2;i<=n;++i)
    {
        while(k!=0 && dif[k+1]!=dif[i])
            k=regula[k+1];
        if(dif[k+1]==dif[i])
            k++;
        regula[i]=k;
    }
    printf("%d\n",n-1-regula[n-1]);
    for(i=1;i<n-regula[n-1];++i)
        printf("%d\n",dif[i]);
    return 0;
}