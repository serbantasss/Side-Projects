#include <bits/stdc++.h>
using namespace std;
char S[100005],s[100005];
int main()
{
    freopen("sr.in","r",stdin);
    freopen("sr.out","w",stdout);
    int n,N,i,j;
    scanf("%s",S);
    scanf("%s",s);
    N=strlen(S);
    n=strlen(s);
    for(i=0,j=0;i<N && j<n;i++)
    {
        if(S[i]==s[j])
        {
            printf("%d ",i+1);
            j++;
        }
    }
    return 0;
}