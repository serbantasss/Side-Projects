//
//  main.cpp
//  economie
//
//  Created by Serban Bantas on 29/11/2019.
//  Copyright © 2019 Serban Bantas. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int f[50005];
int v[1005];
vector<int> afis;
int main(int argc, const char * argv[])
{
    freopen("economie.in","r",stdin);
    freopen("economie.out","w",stdout);
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    f[0]=1;
    for(i=1;i<=n;++i)
    {
        if(f[v[i]]==0)
        {
            afis.push_back(v[i]);
            for(int j=0;j<=50000-v[i];++j)
                if(f[j]==1)
                    f[j+v[i]]=1;
        }
    }
    printf("%lu\n",afis.size());
    for(i=0;i<afis.size();++i)
        printf("%d\n",afis[i]);
    return 0;
}