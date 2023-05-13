#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
char s[100005],ch;
int f[200];
vector<int> poz[200];
long long len,q,k,frec,n1,n2;
inline long long biti(long long nr){
    long long bits = 0;
    while(nr > 0){
        bits++;
        nr -= (nr & -nr);
    }
    return bits;
}
inline char caps(char c)
{
    if(c>='A' && c<='Z')
        c=c-'A'+'a';
    else
        c=c+'A'-'a';
    return c;
}
void findch()
{
    k--;
    frec=0;
    long long x=k/len,y=k%len;
    if(biti(x)%2)
        ch=caps(s[y]);
    else
        ch=s[y];
    n1=n2=x/2;
    if(x%2)
    {if(biti(x-1)%2==0)
        n1++;
    else
        n2++;
    }
    frec=n1*f[ch]+n2*f[caps(ch)]+upper_bound(poz[s[y]].begin(), poz[s[y]].end(), y)-poz[s[y]].begin();
}
int main()
{
    freopen("caps.in","r",stdin);
    freopen("caps.out","w",stdout);
    scanf("%lld%lld\n",&len,&q);
    scanf("%s",s);
    for(int i=0;i<len;++i)
    {
        f[s[i]]++;
        poz[s[i]].push_back(i);
    }
    while(q--)
    {
        
        scanf("%lld",&k);
        findch();
        printf("%c %lld\n",ch,frec);
    }
    return 0;
}