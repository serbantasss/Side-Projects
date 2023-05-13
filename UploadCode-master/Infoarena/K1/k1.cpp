#include<stdio.h>
#define f (dr1)-(st1)
#define g (dr2)-(st2)
int v[25000];
long long Q[1000010];
long long R[1000010],N,x,st1,dr1,st2,dr2,min,nr1,nr2,a,b;
long long S;
int afis()
{
    for(int i=st1; i<dr1; ++i)
        printf("%d ",Q[i]);
    for(int i=st2; i<dr2; ++i)
        printf("%d ",R[i]);
    printf("\n");
}
int main()
{
    freopen("k1.in","r",stdin);
    freopen("k1.out","w",stdout);
    scanf("%d",&N);
    for(int i=1; i<=N; ++i)
    {
        scanf("%d",&x);
        ++v[x];
    }
    for(int i=1; i<25000; ++i)
    {
        while(v[i])
        {
            Q[dr1++]=i;
            --v[i];
        }
    }
    while(f+g>1)
    {
        min=0,nr1=0,nr2=0;
        if(dr1-st1>0 && dr2-st2>0)
        {
            if(Q[st1]+R[st2]<min||min==0);
            {
                min=Q[st1]+R[st2];
                nr1=1;
                nr2=2;
            }
        }
        if(dr1-st1>1)
        {
            if(Q[st1]+Q[st1+1]<min||min==0)
            {

                min=Q[st1]+Q[st1+1];
                nr1=1;
                nr2=1;
            }
        }
        if(dr2-st2>1)
        {
            if(R[st2]+R[st2+1]<min||min==0)
            {
                min=R[st2]+R[st2+1];
                nr1=2;
                nr2=2;
            }
        }
        S+=min;
        a=nr1;
        b=nr2;
        if(a==1&&b==1)
        {
            st1+=2;
            R[dr2++]=min;
        }
        if(a==1&&b==2)
        {
            st1++;
            st2++;
            R[dr2++]=min;
        }
        if(a==2&&b==2)
        {
            st2++;
            st2++;
            R[dr2++]=min;
        }
    }
    printf("%lld",S);
    return 0;
}