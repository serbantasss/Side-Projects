#include <cstdio>
using namespace std;
int v[100005];
int main()
{
    freopen("cautbin.in","r",stdin);
    freopen("cautbin.out","w",stdout);
    int n,q;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%d",&v[i]);
    scanf("%d",&q);
    while(q--)
    {
        int op,x;
        scanf("%d %d",&op,&x);
        if(op==0)
        {
            int st=1,dr=n,mid,ok=0,pos;
            while(st<=dr)
            {
                mid=st+(dr-st)/2;
                if(v[mid]==x)
                    ok=1,pos=mid,st=mid+1;
                else if(v[mid]>x)
                    dr=mid-1;
                else
                    st=mid+1;
            }
            if(ok)
                printf("%d\n",pos);
            else
                printf("-1\n");
        }
        if(op==1)
        {
            int st=1,dr=n,mid,pos;
            while(st<=dr)
            {
                mid=st+(dr-st)/2;
                if(v[mid]<=x)
                    pos=mid,st=mid+1;
                else
                    dr=mid-1;
            }
            printf("%d\n",pos);
        }
        if(op==2)
        {
            int st=1,dr=n,mid,pos;
            while(st<=dr)
            {
                mid=st+(dr-st)/2;
                if(v[mid]>=x)
                    pos=mid,dr=mid-1;
                else
                    st=mid+1;
            }
            printf("%d\n",pos);
        }
    }
    return 0;
}