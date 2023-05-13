#include <cstdio>
#include <algorithm>
using namespace std;
struct cojo
{
    int m;
    long long s;
}v[100005];
bool mycmp(cojo a,cojo b)
{
    if(a.m==b.m)
        return a.s<b.s;
    return a.m<b.m;
}
int main()
{
    int n,d,st,dr;
    long long s,smax=0;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;++i)
        scanf("%d%lld",&v[i].m,&v[i].s);
    sort(v+1,v+n+1,mycmp);
    st=1;
    s=v[1].s;
    for(dr=2;dr<=n;++dr)
    {
        if(v[dr].m-v[st].m<d)
            s+=v[dr].s;
        else
        {
            if(s>smax)
                smax=s;
            s-=v[st].s;
            st++;
            while(v[dr].m-v[st].m>=d)
            {
                s-=v[st].s;
                st++;
            }
            s+=v[dr].s;
        }
    }
    if(s>smax)
        smax=s;
    printf("%lld",smax);
    return 0;
}