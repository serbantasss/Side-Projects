#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;
int plus9=9999;
int f[20005];
char s[1005];
int main()
{
    freopen("ec.in","r",stdin);
    freopen("ec.out","w",stdout);
    int n,p,i,j,len,k,e1=0,e2=0,ec1=0,ec2=0;
    scanf("%d", &n);
    scanf("%d", &p);
    for(i=1;i<=n*n;++i)
        {
        scanf("%d\n",&k);
          f[k+plus9]++;
        }
    for(i=1;i<=p;++i)
    {
        scanf("%s\n",s);
        len=strlen(s);
        int a,b,c,d,ec=1;
        for(j=0;j<len;++j)
            if(s[j]=='^')
                {ec=2;
                break;}
        if(ec==1)
        {
            e1++;
            a=b=c=0;
            k=1;
            for(j=0;j<len;++j)
            {
                if(s[j]=='x')
                    k++,j++;
                else if(s[j]=='=')
                    k++;
                else
                {
                    if(k==1)
                        a=a*10+s[j]-'0';
                    if(k==2)
                        b=b*10+s[j]-'0';
                    if(k==3)
                        c=c*10+s[j]-'0';
                }
            }
            if(a!=0)
            {
                if((c-b)%a==0 && f[(c-b)/a+plus9])
                    ec1++;
            }
        }
        else
        {
            e2++;
            a=b=c=d=0;
            j=0;
            while(isdigit(s[j]))
                a=a*10+s[j]-'0',j++;
            j+=4;
            while(isdigit(s[j]))
                b=b*10+s[j]-'0',j++;
            j+=2;
            while(isdigit(s[j]))
                c=c*10+s[j]-'0',j++;
            j++;
            while(isdigit(s[j]))
                d=d*10+s[j]-'0',j++;
            c-=d;
            double delta=b*b-4*a*c;
            if(a==0)
            {
                if(b==0)
                    continue;
                if((-c)%b==0 && f[(-c)/b+plus9])
                    ec2++;
                continue;
            }
            if(delta<0)
                continue;
            int x=sqrt(delta);
            double y=sqrt(delta);
            if(x==y)
            {
                if((-b+x)%(2*a)!=0)
                    continue;
                if((-b-x)%(2*a)!=0)
                    continue;
                if(f[(-b-x)/(2*a)+plus9] && f[(-b+x)/(2*a)+plus9])
                    ec2++;
            }
        }
    }
    printf("%d %d\n%d %d",e1,ec1,e2,ec2);
    return 0;
}