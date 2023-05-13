#include <bits/stdc++.h>
using namespace std;
int fiu[10005],tata[10005],n,m,e,ans=0;
bool viz[10005];
vector<int> adc[10005];
inline void zero()
{
    for(int i=1;i<=10005;++i)
        viz[i]=0;
}
bool cuplaj(int nod)
{
    if(viz[nod])
        return 0;
    viz[nod]=1;
    for(int i=0;i<adc[nod].size();++i)
        if(tata[adc[nod][i]]==0 || cuplaj(tata[adc[nod][i]]))
        {
            fiu[nod]=adc[nod][i];
            tata[adc[nod][i]]=nod;
            return 1;
        }
    return 0;
}
int main()
{
    freopen("senat.in","r",stdin);
    freopen("senat.out","w",stdout);
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x;
        while(1)
        {
            char ch;
            scanf("%c",&ch);
            if(ch=='\n')
                break;
            if(ch==' ')
                continue;
            x=0;
            while(ch>='0' && ch<='9')
            {
                x=x*10+ch-'0';
                scanf("%c",&ch);
            }
            adc[i].push_back(x);
            if(ch=='\n')
                break;
        }
    }
    while(1)
    {
        bool ok=0;
        zero();
        for(int i=1;i<=m;++i)
            if(fiu[i]==0 && cuplaj(i) )
            {
                ans++;
                ok=1;
            }
        if(!ok)
            break;
    }
    if(ans==m)
    {
        for(int i=1;i<=m;++i)
            if(fiu[i])
                printf("%d\n",fiu[i]);
    }
    else
        printf("0\n");
    return 0;
}