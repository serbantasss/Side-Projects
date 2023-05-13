#include <bits/stdc++.h>
using namespace std;
 
int main()
{
//    freopen("sediu.in","r",stdin);
//    freopen("sediu.out","w",stdout);
    int n,n1=0,n2=0;
    scanf("%d\n",&n);
    for(int i=1;i<=n;++i)
    {
        char ch;
        scanf("%c",&ch);
        if(ch=='z')
            n1++;
        if(ch=='n')
            n2++;
    }
    for(int i=1;i<=n2;++i)
        printf("1 ");
    for(int i=1;i<=n1;++i)
        printf("0 ");
    return 0;
}