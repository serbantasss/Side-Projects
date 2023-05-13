#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100005];
char st[100005];
int main()
{
    freopen("charlie.in","r",stdin);
    freopen("charlie.out","w",stdout);
    int cer,n;
    scanf("%d\n",&cer);
    scanf("%s",s);
    n=strlen(s);
    if(cer==1)
    {
        int lmax=0,ok=0,l=0;
        for(int i=1; i<n-1; i++)
            if(s[i]<s[i-1] && s[i]<s[i+1] && !ok)
                l=3,ok=1,i++;
            else if(s[i]<s[i-1] && s[i]<s[i+1] && ok)
                l+=2,i++;
            else
            {
                if(lmax<l)
                    lmax=l;
                ok=0;
            }
        if(lmax<l)
            lmax=l;
        printf("%d",lmax);
    }
    else
    {
        int top=2,ind=2;
        long long ans=0;
        st[1]=s[0];
        st[2]=s[1];
        while(ind<n)
        {
            st[++top]=s[ind++];
            while(top>=3 && st[top-1]<st[top-2] && st[top-1]<st[top])
                {
                    ans+=max(st[top],st[top-2])-'a'+1;
                    st[top-1]=st[top];
                    st[top]=0;
                    top--;
                }
        }
        for(int i=1;i<=top;++i)
            printf("%c",st[i]);
        printf("\n%lld",ans);
    }
    return 0;
}