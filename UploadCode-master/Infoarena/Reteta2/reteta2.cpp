#include <cstdio>
#include <string>
#include <map>
#include <cctype>
#include <cstring>

using namespace std;
map<string,int> vaginator3000;
char s[2000];
int main()
{
    freopen("reteta2.in","r",stdin);
    freopen("reteta2.out","w",stdout);
    int timp=0,cant,cif,n,i,j;
    fgets(s, sizeof(s), stdin);
    n=strlen(s);
    for(i=0; i<n; ++i)
    {
        if(isalpha(s[i]))
        {
            string st;
            while(isalpha(s[i]))
            {
                st+=s[i];
                i++;
            }
            while(s[i]==' ')
                i++;
            cant=0;
            while(isdigit(s[i]))
            {
                cif=s[i]-'0';
                cant=cant*10+cif;
                i++;
            }
            i--;
            vaginator3000[st]+=cant;
        }
        else if(s[i]==')')
        {
            while(!isdigit(s[i]))
                i++;
            cant=0;
            while(isdigit(s[i]))
            {
                cif=s[i]-'0';
                cant=cant*10+cif;
                i++;
            }
            i--;
            timp+=cant;
        }
    }
    printf("%d\n",timp);
    map<string,int>::iterator it;
    for(it=vaginator3000.begin();it!=vaginator3000.end();++it)
        printf("%s %d\n",it->first.c_str(),it->second);
    return 0;
}