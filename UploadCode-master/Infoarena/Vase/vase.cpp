#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
deque< pair<long long int,long long int> >v;
int main()
{
    freopen("vase.in","r",stdin);
    freopen("vase.out","w",stdout);
    long long int n,i,vol,vtot=0,x,m1,m2,sl;
    char cl1,cl2;
    scanf("%lld\n",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%lld %c\n",&vol,&cl1);
        vtot+=vol;
        if(cl1=='D')
            v.push_back(make_pair(vol,i));
        else
            v.push_front(make_pair(vol,i));
    }
    scanf("%lld",&x);
    printf("%lld\n",vtot/2);
    sl=-vtot/2;
   // for(i=0; i<v.size(); i++)
     //   printf("%d %d\n",v[i].first,v[i].second);
    for(i=0; i<v.size(); i++)
        if(v[i].second==x)
        {
            if(sl+v[i].first>0 && sl<0)
            {
                cl1='S';
                cl2='D';
                m1=-sl;
                m2=sl+v[i].first;
            }
            else if(sl+v[i].first>=0 && sl>=0)
            {
                cl1='D';
                cl2='D';
                m2=sl;
                m1=sl+v[i].first;
            }
            else
            {
                cl1='S';
                cl2='S';
                m1=-sl;
                m2=-(sl+v[i].first);
            }
            break;
        }
        else
            sl+=v[i].first;
    printf("%lld %c\n%lld %c\n",m1,cl1,m2,cl2);
    return 0;
}