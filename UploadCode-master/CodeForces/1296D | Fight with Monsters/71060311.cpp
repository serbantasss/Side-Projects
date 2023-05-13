#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
    //freopen("disconnect.in","r",stdin);
    //freopen("disconnect.out","w",stdout);
    int n,a,b,k,x,ans=0;
    scanf("%d%d%d%d",&n,&a,&b,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        if(x%(a+b)==0)
            v.push_back(a+b);
        else
            v.push_back(x%(a+b));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i)
        if(v[i]<a)
            ans++;
        else
            if(v[i]%a==0)
            {
                if(v[i]/a-1<=k)
                    ans++,k-=v[i]/a-1;
            }
            else
                if(v[i]/a<=k)
                    ans++,k-=v[i]/a;
    printf("%d",ans);
    return 0;
}