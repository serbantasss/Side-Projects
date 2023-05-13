#include <cstdio>

using namespace std;
struct coada
{
    int r,t;
    bool c;
};
coada q[2000005];
bool viz[2000005],sol[2000005];
int cmmdc(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    freopen("multiplu.in","r",stdin);
    freopen("multiplu.out","w",stdout);
    int a,b,m,p,u,soln=0,r;
    coada temp;
    scanf("%d%d",&a,&b);
    m=a*b/cmmdc(a,b);
    q[1].c=1;
    q[1].t=0;
    q[1].r=1;
    p=1;
    u=1;
    viz[1]=1;
    while(p<=u)
    {
        temp=q[p];
        r=(temp.r*10+0)%m;
        if(!viz[r])
        {
            viz[r]=1;
            u++;
            q[u].c=0;
            q[u].r=r;
            q[u].t=p;
            if(r==0)
                {
                    int ok1=1;
                    while(1)
                    {
                        if(u!=0)
                           sol[++soln]=q[u].c;
                        if(u==0)
                                break;
                        u=q[u].t;
                    }
                }
        }
        r=(temp.r*10+1)%m;
        if(!viz[r])
        {
            viz[r]=1;
            u++;
            q[u].c=1;
            q[u].r=r;
            q[u].t=p;
            if(r==0)
                {   int ok1=1;
                    while(1)
                    {
                        if(u!=0)
                           sol[++soln]=q[u].c;
                        if(u==0)
                                break;
                        u=q[u].t;
                    }
                }
        }
        p++;
    }
    for(int i=soln;i>=1;--i)
        printf("%d",sol[i]);
    return 0;
}