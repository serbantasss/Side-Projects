/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <cstdio>
#include <cstdlib>
using namespace std;
int v1[100005],v2[100005];
int main()
{
    int n,m1,m2,i,k=0,ok=0,ma=0,r=0,l=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&v1[i],&v2[i]);
        r+=v1[i];
        l+=v2[i];
    }
    ma=abs(l-r);
    for(i=1;i<=n;++i)
    {
        m1=r-v1[i]+v2[i];
        m2=l-v2[i]+v1[i];
        if(abs(m1-m2)>ma)
        {
            ma=abs(m1-m2);
            k=i;
        }
    }
    printf("%d",k);
    return 0;
}