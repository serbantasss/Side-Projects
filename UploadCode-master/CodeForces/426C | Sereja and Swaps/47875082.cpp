#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int v[205];
int main()
{
    int n,m,i,j,k,st,dr,sek,maxim,sum;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; ++i)
        scanf("%d",&v[i]);
    maxim=v[1];
    for(st=1; st<=n; ++st)
        for(dr=st; dr<=n; ++dr)
        {
            vector<int>elem;
            vector<int>afar;
            for(i=1; i<=n; ++i)
                if(i>=st && i<=dr)
                    elem.push_back(v[i]);
                else
                    afar.push_back(v[i]);
            sek=k,sum=0;
            sort(afar.begin(),afar.end());
            sort(elem.begin(),elem.end());
            for(i=0; i<elem.size(); ++i)
                if(sek>0 && !afar.empty())
                {
                    if(afar[afar.size()-1]>elem[i])
                    {
                        sum+=afar[afar.size()-1];
                        afar.pop_back();
                        sek--;
                    }
                    else
                        sum+=elem[i];
                }
                else
                    sum+=elem[i];
            if(sum>maxim)
                maxim=sum;
        }
    printf("%d",maxim);
    return 0;
}