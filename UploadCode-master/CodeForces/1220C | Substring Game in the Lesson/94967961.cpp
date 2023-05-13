#include <bits/stdc++.h>
using namespace std;
char s[500005];
bool v[500005];
int main()
{
//    freopen("sediu.in","r",stdin);
//    freopen("sediu.out","w",stdout);
    int n,indmi=0;
    gets(s);
    n=strlen(s);
    v[0]=0;
    for(int i=1;i<n;++i)
        if(s[i]>s[indmi])
            v[i]=1;
        else
            v[i]=0,indmi=i;
    for(int i=0;i<n;++i)
        if(v[i])
            printf("Ann\n");
        else
            printf("Mike\n");
    return 0;
}