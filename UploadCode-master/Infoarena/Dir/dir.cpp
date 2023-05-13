#include <bits/stdc++.h>
using namespace std;
char s[2005];
vector<string> out;
void analiz(int st,int dr,string prefix)
{
    for(int i=st;i<=dr;++i)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            string fold;
            while(s[i]!='(')
                    fold+=s[i],i++;
            int i2=i,ok=1;
            while(ok)
                {
                    i2++;
                    if(s[i2]=='(')
                        ok++;
                    if(s[i2]==')')
                        ok--;
                }
            analiz(i+1,i2-1,prefix+'\\'+fold);
            i=i2;
        }
        if(s[i]>='a' && s[i]<='z')
        {
            int i2=i;
            string fis;
            while(s[i2]!=')' && s[i2]!=',')
                fis+=s[i2++];
            out.push_back(prefix+'\\'+fis);
            i=i2;
        }
    }
}
int main()
{
    freopen("dir.in","r",stdin);
    freopen("dir.out","w",stdout);
    scanf("%s",s);
    int n=strlen(s),i;
    string root;
    for(i=0;i<n;++i)
        if(s[i]=='(')
           break;
        else
            root+=s[i];
    analiz(i+1,n-2,root);
    sort(out.begin(),out.end());
    printf("%d\n",out.size());
    for(i=0;i<out.size();++i)
        printf("%s\n",out[i].c_str());
    return 0;
}