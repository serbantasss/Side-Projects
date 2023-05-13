#include <cstdio>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
char s[100005];
int main()
{
    freopen("editor.in","r",stdin);
    freopen("editor.out","w",stdout);
    int t,n,i;
    char ch;
    scanf("%d\n",&t);
    for(; t; --t)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        n=strlen(s);
        string fmm;
        for(i=0; i<n-1; ++i)
            if(s[i]=='*')
                if(!fmm.empty())
                    fmm.erase(fmm.size()-1);
                else
                    continue;
            else
                fmm+=s[i];
        n=fmm.size();
        stack<char> st;
        for(i=0; i<n; ++i)
            if(fmm[i]=='(' || fmm[i]=='[')
                st.push(fmm[i]);
            else
            {
                if(!st.empty())
                {
                    if(st.top()=='(' )
                    {
                        if(fmm[i]==')')
                            st.pop();
                        else
                            st.push(fmm[i]);
                    }
                    else if(st.top()=='[')
                    {
                        if(fmm[i]==']')
                            st.pop();
                        else
                            st.push(fmm[i]);
                    }
                }
                else
                    st.push(fmm[i]);
            }
        if(!st.empty())
            printf(":(\n");
        else
            printf(":)\n");
    }
    return 0;
}