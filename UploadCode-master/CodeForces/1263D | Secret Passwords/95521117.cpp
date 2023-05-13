#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
bool adc[30][30],frec[30],f[30];
bool viz[30];
char s[1000005];
void dfs(int nod)
{
    viz[nod]=1;
    for(int i=1;i<30;++i)
        if(adc[nod][i] && !viz[i])
            dfs(i);
}
int main()
{
    int n,len,conx=0;
    scanf("%d\n",&n);
    while(n--)
    {
        gets(s);
        for(int i=0;i<30;++i)
            frec[i]=0;
        len=strlen(s);
        for(int i=0;i<len;++i)
            frec[s[i]-'a'+1]=f[s[i]-'a'+1]=1;
        for(int i=1;i<30;++i)
            for(int j=1;j<30;++j)
                if(i!=j && frec[i] && frec[j])
                    adc[i][j]=adc[j][i]=1;
    }
    for(int i=1;i<30;++i)
        if(f[i] && !viz[i])
            dfs(i),++conx;
    printf("%d",conx);
    return 0;
}