#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> ab;
vector<int> ac;
vector<int> bc;
vector<int> abc;
int main()
{
    int n,i,p;
    char ch;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d ",&p);
        bool ea=0,eb=0,ec=0;
        while(1)
        {
            scanf("%c",&ch);
            if(ch=='\n')
                break;
            if(ch=='A')
                ea=1;
            if(ch=='B')
                eb=1;
            if(ch=='C')
                ec=1;
        }
        if(ea==1 && eb==0 && ec==0)
            a.push_back(p);
        if(ea==0 && eb==1 && ec==0)
            b.push_back(p);
        if(ea==0 && eb==0 && ec==1)
            c.push_back(p);
        if(ea==1 && eb==1 && ec==0)
            ab.push_back(p);
        if(ea==0 && eb==1 && ec==1)
            bc.push_back(p);
        if(ea==1 && eb==0 && ec==1)
            ac.push_back(p);
        if(ea==1 && eb==1 && ec==1)
            abc.push_back(p);
    }
    a.push_back(300005);
    sort(a.begin(),a.end());
    b.push_back(300005);
    sort(b.begin(),b.end());
    c.push_back(300005);
    sort(c.begin(),c.end());
    ab.push_back(300005);
    sort(ab.begin(),ab.end());
    bc.push_back(300005);
    sort(bc.begin(),bc.end());
    ac.push_back(300005);
    sort(ac.begin(),ac.end());
    abc.push_back(300005);
    sort(abc.begin(),abc.end());
    int mi=abc[0];
    mi=min(mi,a[0]+b[0]+c[0]);
    mi=min(mi,ab[0]+c[0]);
    mi=min(mi,bc[0]+a[0]);
    mi=min(mi,ac[0]+b[0]);
    mi=min(mi,ab[0]+ac[0]);
    mi=min(mi,bc[0]+ac[0]);
    mi=min(mi,ab[0]+bc[0]);
    if(mi>300000)
        printf("-1");
    else
        printf("%d",mi);
    return 0;
}