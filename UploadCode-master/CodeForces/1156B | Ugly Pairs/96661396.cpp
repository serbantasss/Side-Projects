#include <bits/stdc++.h>
using namespace std;
char s[1005],par[1005],imp[1005];
int main()
{
    //freopen("1.in","r",stdin);
   // freopen("1.out","w",stdout);
    int test;
    scanf("%d\n",&test);
    while(test--)
    {
        int n,n1=0,n2=0,ok=0,i1,i2;
        gets(s);
        n=strlen(s);
        for(int i=0;i<n;++i)
            if(s[i]%2==0)
                par[n1++]=s[i];
            else
                imp[n2++]=s[i];
        for(int i=0;i<n1 && !ok;++i)
            for(int j=0;j<n2 && !ok;++j)
                if((par[i]-1)!=imp[j] && (par[i]+1)!=imp[j])
                    ok=1,i1=i,i2=j;
        if(n1==0)
        {
            for(int i=0;i<n2;++i)
                printf("%c",imp[i]);
            printf("\n");
            continue;
        }
        if(n2==0)
        {
            for(int i=0;i<n1;++i)
                printf("%c",par[i]);
            printf("\n");
            continue;
        }
        if(ok)
        {
            char aux=par[0];
            par[0]=par[i1];
            par[i1]=aux;
            aux=imp[n2-1];
            imp[n2-1]=imp[i2];
            imp[i2]=aux;
            for(int i=0;i<n2;++i)
                printf("%c",imp[i]);
            for(int i=0;i<n1;++i)
                printf("%c",par[i]);
            printf("\n");
        }
        else
            printf("No answer\n");
    }
    return 0;
}