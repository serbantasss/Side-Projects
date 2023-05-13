#include <bits/stdc++.h>
 
using namespace std;
vector<int>v;
int main()
{
    int n,i,j,zero=0,neg=0,poz=0,x;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        if(x>0)
            poz++;
        if(x<0)
            neg++;
        v.push_back(x);
    }
    zero=n-poz-neg;
    sort(v.begin(),v.end());
    if(poz==0 && neg%2==0)
    {
        printf("%d ",neg-3);
        for(i=0;i<neg-3;++i)
            printf("%d ",v[i]);
        printf("\n2 %d %d\n",v[neg-3],v[neg-2]);
        printf("%d ",zero+1);
        for(i=neg-1;i<n;++i)
            printf("%d ",v[i]);
        printf("\n");
        return 0;
    }
    if(poz==0 && neg%2==1)
    {
        printf("%d ",neg-2);
        for(i=0;i<neg-2;++i)
            printf("%d ",v[i]);
        printf("\n2 %d %d\n",v[neg-2],v[neg-1]);
        printf("%d ",zero);
        for(i=neg;i<n;++i)
            printf("%d ",v[i]);
        printf("\n");
        return 0;
    }
    if(poz>0&& neg%2==0)
    {
       printf("%d ",neg-1);
       for(i=0;i<neg-1;++i)
            printf("%d ",v[i]);
       printf("\n%d ",poz);
       for(i=zero+neg;i<n;++i)
            printf("%d ",v[i]);
       printf("\n%d ",zero+1);
       for(i=neg-1;i<zero+neg;++i)
            printf("%d ",v[i]);
       printf("\n");
        return 0;
    }
    if(poz>0&& neg%2==1)
    {
       printf("%d ",neg);
       for(i=0;i<neg;++i)
            printf("%d ",v[i]);
       printf("\n%d ",poz);
       for(i=zero+neg;i<n;++i)
            printf("%d ",v[i]);
       printf("\n%d ",zero);
       for(i=neg;i<zero+neg;++i)
            printf("%d ",v[i]);
       printf("\n");
        return 0;
    }
    return 0;
}