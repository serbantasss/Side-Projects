#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
 
using namespace std;
int st[100005],dr[100005];
char s[100005];
int main()
{
    int t,n,i,x,y,d,ans=0,nrg=0;
    char ch;
    scanf("%d\n",&n);
    gets(s);
    for(i=0;i<=n;++i)
        if(s[i]=='G')
        {
            st[i]=1;
            if(i>0)
                st[i]=st[i-1]+1;
        }
    for(i=n-1;i>=0;--i)
        if(s[i]=='G')
        {
            dr[i]=1;
            nrg++;
            if(i>0)
                dr[i]=dr[i+1]+1;
        }
    if(nrg==n || nrg==0)
    {
        printf("%d",nrg);
        return 0;
    }
    for(i=0;i<n;++i)
        if(s[i]=='S')
    {
        if(i==0)
            d=dr[i+1]+1;
        else
        if(i==n-1)
            d=st[i-1]+1;
        else
            d=st[i-1]+dr[i+1]+1;
        if(ans<d)
            ans=d;
    }
    if(ans>nrg)
        ans=nrg;
    printf("%d",ans);
    return 0;
}