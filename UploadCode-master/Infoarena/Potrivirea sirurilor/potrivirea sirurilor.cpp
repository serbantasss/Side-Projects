#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
char s1[2000005],s2[2000005];
int pref[2000005];
vector<int> ans;
int main()
{
    freopen("strmatch.in","r",stdin);
    freopen("strmatch.out","w",stdout);
    int n,m,k,aa=0;
    scanf("%s %s",s1,s2);
    n=strlen(s1);
    m=strlen(s2);
    for(int i=n;i>=1;--i)
        s1[i]=s1[i-1];
    for(int i=m;i>=1;--i)
        s2[i]=s2[i-1];
    s1[n+1]=s2[m+1]=s1[0]=s2[0]='$';
    k=0;
    pref[1]=0;
    for(int i=2;i<=n;++i)
    {
        while(k>0 && s1[i]!=s1[k+1])
            k=pref[k];
        if(s1[i]==s1[k+1])
            k++;
        pref[i]=k;
    }
    k=0;
    for(int i=1;i<=m;++i)
    {
        while(k>0 && s2[i]!=s1[k+1])
            k=pref[k];
        if(s2[i]==s1[k+1])
            k++;
        if(k==n)
        {
            k=pref[n];
            aa++;
            if(aa<=1005)
                ans.push_back(i-n);
        }
    }
    printf("%d\n",aa);
    for(int i=0;i<ans.size() && i<1000;++i)
        printf("%d ",ans[i]);
    return 0;
}