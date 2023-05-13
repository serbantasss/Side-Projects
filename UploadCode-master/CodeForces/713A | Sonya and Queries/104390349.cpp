#include <bits/stdc++.h>
using namespace std;
map<long long,int>mp;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char ch;
        long long x,p2=1,y=0;
        scanf("\n%c %lld",&ch,&x);
        do
        {
            if((x%10)%2==1)
                y+=p2;
            p2*=2;
            x/=10;
        }while(x>0);
        if(ch=='+')
            mp[y]++;
        else
            if(ch=='-')
                mp[y]--;
            else
                printf("%d\n",mp[y]);
    }
    return 0;
}