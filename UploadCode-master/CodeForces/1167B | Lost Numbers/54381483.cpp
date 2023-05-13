#include <bits/stdc++.h>
using namespace std;
int a[]={0, 4 , 8, 15, 16, 23, 42};
int b[5];
int main()
{
    int n=6,i,j;
    for(i=1;i<5;++i)
    {
        printf("? %d %d\n",i,i+1);
        fflush(stdout);
        scanf("%d",&b[i]);
    }
    while(1)
    {
        bool ok=1;
        for(i=1;i<5 && ok;++i)
            if(a[i]*a[i+1]!=b[i])
                ok=0;
        if(ok==1)
            {printf("! %d %d %d %d %d %d",a[1],a[2],a[3],a[4],a[5],a[6]);
            break;}
        else
            next_permutation(a,a+7);
    }
    return 0;
}