#include<bits/stdc++.h>
using namespace std;
struct cojo
{
    int t,a,b;
};
cojo t[500005];
map<int,int> q;
bool mycmp(cojo a,cojo b)
{
    if(a.t==b.t)
        if(a.a==b.a)
            return a.b<b.b;
        else
            return a.a<b.a;
    else
        return a.t<b.t;
}
int main()
{
    //freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    int T,n,m,tot,now,need;
    long long ans,x,y;
    bool ok;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        ok=false;
        q.clear();
        scanf("%d%d%d%d",&n,&m,&tot,&now);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&t[i].t,&t[i].a,&t[i].b);
        sort(t+1,t+n+1,mycmp);
        t[++n].t=m;
        q[0]=now;
        for(int i=1;i<=n;i++)
        {
            need=t[i].t-t[i-1].t;
            if(now<need)
            {
                ok=true;
                break;
            }
            now-=need;
            while(need)
            {
                x=q.begin()->first;
                y=q.begin()->second;
                if(y<=need)
                {
                    ans+=x*y;
                    q.erase(x);
                    need-=y;
                }
                else
                {
                    ans+=need*x;
                    q[x]-=need;
                    need=0;
                }
            }
            now+=t[i].a;q[t[i].b]+=t[i].a;
            while(now>tot)
            {
                x=q.rbegin()->first;
                y=q.rbegin()->second;
                if(now-tot>=y)
                {
                    now-=y;
                    q.erase(x);
                }
                else
                {
                    q[x]-=now-tot;
                    now=tot;
                }
            }
        }
        if(ok)
            printf("-1\n");
        else
            printf("%lld\n",ans);
    }
    return 0;
}