#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[300005];
long long n,ans,num;
int main()
{
    scanf("%lld\n%s",&n,s);
    ans=n*(n-1)/2;
    num=1;
    for( int i=1; i<n; i++ )
    {
        if( s[i]==s[i-1] )
            num++;
        else
            ans-=num,num=1;
    }
    num=1;
    for( int i=n-2; i>=0; i-- )
    {
        if( s[i]==s[i+1] )
            num++;
        else
            ans-=num-1,num=1;
    }
    printf("%lld",ans);
    return 0;
}