#include <bits/stdc++.h>
using namespace std;
char s1[100005],s2[100005];
int op1[100005],op2[100005];
int main()
{
    int q;
    scanf("%d\n",&q);
    while(q--)
    {
        int n,o1=0,o2=0;
        scanf("%d\n",&n);
        gets(s1);
        gets(s2);
        for(int i=1;i<n;i++)
        {
            if(s1[i]!=s1[i-1])
                op1[++o1]=i;
            if(s2[i]!=s2[i-1])
                op2[++o2]=i;
        }
        if(s1[n-1]=='1')
            op1[++o1]=n;
        if(s2[n-1]=='1')
            op2[++o2]=n;
        printf("%d ",o1+o2);
        for(int i=1;i<=o1;++i)
            printf("%d ",op1[i]);
        for(int i=o2;i>=1;--i)
            printf("%d ",op2[i]);
        printf("\n");
    }
    return 0;
}