#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> dq;
int sum(int x)
{
    int s=0;
    do
    {
        s+=x%10;
        x/=10;
    }while(x);
    return s;
}
int main()
{
    freopen("piata.in","r",stdin);
    freopen("piata.out","w",stdout);
    int n,i,x1,y1,x2,y2,j,aux;
    long long s=0,stot=0;
    scanf("%d\n",&n);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    for(j=0,i=n-x1+2;i<=n;++i,++j)
        {
            dq.push_back(sum(i));
            if(j>=y1-1 && j<=y2-1)
                s+=dq[j];
        }
    for(i=1;i<=n-x1+1;++i,j++)
        {
            dq.push_back(sum(i));
            if(j>=y1-1 && j<=y2-1)
                s+=dq[j];
        }
    stot+=s;
    for(i=x1+1;i<=x2;++i)
    {
        s=s-dq[y2-1];
        aux=dq[n-1];
        dq.pop_back();
        dq.push_front(aux);
        s=s+dq[y1-1];
        stot+=s;
    }
    printf("%lld",stot);
    return 0;
}