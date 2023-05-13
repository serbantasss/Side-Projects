#include <bits/stdc++.h>
using namespace std;
map<string,int> adiac;
int mp[15][2],f[15],vf=0;
string cod;
void dfs(int nod)
{
    if(mp[nod][0])
    {
        cod.push_back('0');
        dfs(mp[nod][0]);
        cod.push_back('2');
    }
    if(mp[nod][1])
    {
        cod.push_back('1');
        dfs(mp[nod][1]);
        cod.push_back('2');
    }
}
int main()
{
    freopen("brazi.in","r",stdin);
    freopen("brazi.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        for(int i=1;i<=10;++i)
            mp[i][0]=mp[i][1]=f[i]=0;
        scanf("%d",&n);
        for(int i=1;i<=n-1;++i)
        {
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            mp[x][d]=y;
            f[y]=1;
        }
        vf=0;
        for(int i=1;i<=n && !vf;++i)
            if(f[i]==0)
                vf=i;
        cod.clear();
        dfs(vf);
//        for(int i=0;i<cod.size();++i)
//            printf("%c",cod[i]);
        if(!adiac[cod])
            printf("0\n");
        else
            printf("%d\n",adiac[cod]);
        adiac[cod]++;
    }
    return 0;
}