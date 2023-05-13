#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
char s[200005];
int main()
{
    //freopen("disconnect.in","r",stdin);
    //freopen("disconnect.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,timp=1,mi=INT_MAX,mi1,mi2;
        map<pair<int,int>,int> mp;
        pair<int,int> poz(0,0);//x,y
        scanf("%d\n%s",&l,s);
        mp[poz]=timp++;
        for(int i=0;i<l;++i)
        {
            if(s[i]=='U')
                poz.first++;
            if(s[i]=='D')
                poz.first--;
            if(s[i]=='L')
                poz.second--;
            if(s[i]=='R')
                poz.second++;
            if(mp[poz]>0 && timp-mp[poz]<mi)
                mi=timp-mp[poz],mi1=timp,mi2=mp[poz];
            mp[poz]=timp++;
        }
        if(mi==INT_MAX)
            printf("-1\n");
        else
            printf("%d %d\n",mi2,mi1-1);
    }
    return 0;
}