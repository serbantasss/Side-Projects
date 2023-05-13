#include <bits/stdc++.h>
using namespace std;
string s[1505];
map<string,bool> mp;
int main()
{
    //freopen("furnicik.in","r",stdin);
    //freopen("furnicik.out","w",stdout);
    int n,k,i,j,ii,nr=0;
    scanf("%d%d\n",&n,&k);
    for(i=1;i<=n;++i)
    {
        cin>>s[i];
        mp[s[i]]=1;
    }
    for(i=1;i<=n;++i)
        for(j=i+1;j<=n;++j)
        {
            string c;
            for(ii=0;ii<k;++ii)
                if(s[i][ii]==s[j][ii])
                    c+=s[i][ii];
                else
                {
                    if(s[i][ii]=='S' && s[j][ii]=='E')
                        c+='T';
                    if(s[i][ii]=='S' && s[j][ii]=='T')
                        c+='E';
                    if(s[i][ii]=='E' && s[j][ii]=='T')
                        c+='S';
                    if(s[i][ii]=='E' && s[j][ii]=='S')
                        c+='T';
                    if(s[i][ii]=='T' && s[j][ii]=='S')
                        c+='E';
                    if(s[i][ii]=='T' && s[j][ii]=='E')
                        c+='S';
                }
            if(mp[c])
                nr++;
        }
    printf("%d",nr/3);
    return 0;
}