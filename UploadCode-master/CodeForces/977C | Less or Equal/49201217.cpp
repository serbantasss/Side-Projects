#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int main()
{
    int n,i,l,k,x;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(v[0]==1 && k==0)
        {printf("-1");
    return 0;}
    if(k==0 &&v[0]>1)
    {
        printf("1");
        return 0;
    }
    l=0;
    v.push_back(0);
    for(i=0;i<v.size();++i)
        if(v[i]==v[i+1])
        {
            while(v[i]==v[i+1])
                i++,l++;
            l++;
            if(l==k)
            {
                printf("%d",v[i]);
                return 0;
            }
            if(l>k)
            {
                printf("-1");
                return 0;
            }
        }
        else
            {
            l++;
            if(l==k)
            {
                printf("%d",v[i]);
                return 0;
            }
            }
    return 0;
}