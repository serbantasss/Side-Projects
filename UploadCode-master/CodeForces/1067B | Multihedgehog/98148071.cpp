#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int grad[100005];
//vector<int>adc[100005];
set<int> adc2[100005];
set<int> nod;
//int find(int tata,int fiu)
//{
//    for(int i=0;i<adc[tata].size();++i)
//        if(adc[tata][i]==fiu)
//            return i;
//    return 0;
//}
int main()
{
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adc2[a].insert(b);
        adc2[b].insert(a);
        //adc[a].push_back(b);
        //adc[b].push_back(a);
        grad[a]++;
        grad[b]++;
    }
    for(int i=1;i<=n;++i)
        if(grad[i]==1)
            nod.insert(i);
    while(!nod.empty())
    {
        if(ans==k && nod.size()==1)
        {
            printf("Yes");
            return 0;
        }
        if(ans==k)
        {
            printf("No");
            return 0;
        }
        map<int,int>mp;
        set<int>::iterator it;
        for(it=nod.begin();it!=nod.end();it++)
        {
            //grad[adc[*it][0]]--;
            grad[*adc2[*it].begin()]--;
            //adc[adc[*it][0]].erase(adc[adc[*it][0]].begin()+find(adc[*it][0],*it));
            adc2[*adc2[*it].begin()].erase(*it);
            grad[*it]--;
            //mp[adc[*it][0]]++;
            mp[*adc2[*it].begin()]++;
        }
        nod.clear();
        map<int,int>::iterator it2;
        for(it2=mp.begin();it2!=mp.end();it2++)
            if(it2->second<3)
            {
                printf("No");
                return 0;
            }
        else
            nod.insert(it2->first);
        ans++;
    }
    printf("No");
    return 0;
}