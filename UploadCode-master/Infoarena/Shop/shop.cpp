#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("shop.in");
ofstream cout("shop.out");
struct ban
{
    long long int x;
    int nr,tip;
};
bool cmp(ban a,ban b)
{
    return a.x<b.x;
}
ban v[35],push;
int tip[35];
int main()
{
    int n,i,j,c,a,b;
    long long int x,suma,s,nrmonede=0;
    cin>>n>>c>>suma;
    for(i=1;i<=n;++i)
    {
        cin>>a>>b;
        x=1;
        for(int j=1;j<=a;++j)
            x=x*(long long int)c;
        push.x=x;
        push.nr=b;
        push.tip=i;
        v[i]=push;
    }
    sort(v+1,v+n+1,cmp);
    s=suma;
    for(i=n;i>=1;--i)
    {
        while(s>=v[i].x && v[i].nr>0)
        {
            s-=v[i].x;
            tip[v[i].tip]++;
            v[i].nr--;
            nrmonede++;
        }
    }
    cout<<nrmonede<<"\n";
    for(i=1;i<=n;++i)
    {
        cout<<tip[i]<<" ";
    }
    return 0;
}