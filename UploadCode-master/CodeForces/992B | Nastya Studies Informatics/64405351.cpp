#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
   if (b == 0)
      return a;
   return gcd(b, a % b);
}
int main()
{
    int l,r,x,y;
    scanf("%d%d%d%d",&l,&r,&x,&y);
    if(y%x!=0)
    {
        printf("0");
        return 0;
    }
    int num=y/x,ans=0;
    for (int i=1;i*i<=num;i++)
    {
        int j=num/i;
        if (num%i==0 && gcd(i,j)==1 && (l<=i*x && i*x<=r) && (l<=j*x && j*x<=r))
        {
            if(i==j)
                ans++;
            else
                ans+=2;
        }
    }
    printf("%d",ans);
    return 0;
}