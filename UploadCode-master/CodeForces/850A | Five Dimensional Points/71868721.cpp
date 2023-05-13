//
//  main.cpp
//  lgput
//
//  Created by Serban Bantas on 22/02/2020.
//  Copyright © 2020 Serban Bantas. All rights reserved.
//
 
#include <cstdio>
#include <vector>
using namespace std;
const double pi=3.14159265358979323846264338327950288;
int v[105][5];
vector<int> ind;
bool unghi90(int a,int b,int c)
{
    int s=0;
    for(int i=0;i<5;++i)
        s+=(-v[a][i]+v[b][i])*(-v[a][i]+v[c][i]);
    return s>0;
}
int main()
{
//       freopen("iepuri.in","r",stdin);
//       freopen("iepuri.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n>100)
    {
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=n;++i)
        for(int j=0;j<5;++j)
            scanf("%d",&v[i][j]);
    for(int k=1;k<=n;++k)
    {
        bool ok=1;
        for(int i=1;i<=n && ok;++i)
            for(int j=1;j<=n && ok;++j)
                if(i==k || j==k || i==j)
                    continue;
                else
                    if(unghi90(k,i,j))
                        ok=0;
        if(ok)
            ind.push_back(k);
    }
    printf("%d\n",ind.size());
    for(int i=0;i<ind.size();++i)
        printf("%d ",ind[i]);
    return 0;
}