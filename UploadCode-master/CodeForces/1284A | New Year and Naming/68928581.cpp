#include <bits/stdc++.h>
using namespace std;
string a[25],b[25];
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int n,m,i;
    scanf("%d%d\n",&n,&m);
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=1;i<=m;++i)
        cin>>b[i];
    int q,x;
    scanf("%d",&q);
    for(;q;--q)
    {
        scanf("%d",&x);
        if(x%n==0)
            cout<<a[n];
        else
            cout<<a[x%n];
        if(x%m==0)
            cout<<b[m];
        else
            cout<<b[x%m];
        cout<<"\n";
    }
    return 0;
}