#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char expresie[20010];
int len;
int f[40];
bool mamata[40];
void eval(int st,int dr,int semn)
{
    if(st==dr)
    {
        f[int(expresie[st]-'a')]+=semn;
        return;
    }
    while(st<=dr)
    {
        if(expresie[st]=='*')
        {
            st++;
            continue;
        }
        if(expresie[st]=='/')
        {
            semn*=-1;
            st++;
            if(expresie[st]>='a' && expresie[st]<='z')
            {
                eval(st,st,semn);
                st++;
            }
            if(expresie[st]=='(')
            {
                int cst=st,p=1;
                st++;
                while(p>0)
                {
                    cst++;
                    if(expresie[cst]==')')
                        p--;
                    if(expresie[cst]=='(')
                        p++;
                }
                eval(st,cst-1,semn);
                st=cst+1;
            }
            semn*=-1;
            continue;
        }
        if(expresie[st]>='a' && expresie[st]<='z')
        {
            eval(st,st,semn);
            st++;
            continue;
        }
        if(expresie[st]=='(')
        {
            int cst=st,p=1;
            st++;
            while(p>0)
            {
                cst++;
                if(expresie[cst]==')')
                    p--;
                if(expresie[cst]=='(')
                    p++;
            }
            eval(st,cst-1,semn);
            st=cst+1;
        }
    }
}
int main()
{
    freopen("expresie3.in", "r", stdin);
    freopen("expresie3.out", "w", stdout);
    scanf("%s",expresie);
    len=strlen(expresie);
    for(int i=0;i<len;++i)
        if(expresie[i]>='a' && expresie[i]<='z')
            mamata[int(expresie[i]-'a')]=1;
    eval(0,len-1,1);
    for(char i='a';i<='z';++i)
        if(mamata[i-'a'])
            printf("%c %d\n",i,f[i-'a']);
    return 0;
}