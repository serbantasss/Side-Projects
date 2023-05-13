//
//  main.cpp
//  mata
//
//  Created by Serban Bantas on 22/02/2020.
//  Copyright © 2020 Serban Bantas. All rights reserved.
//
 
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
using namespace std;
int v[100005];
int main(int argc, const char * argv[])
{
    //    freopen("cover1.in","r",stdin);
    //    freopen("cover1.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,ok=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&v[i]);
            if(v[i]==k)
                ok=1;
            v[i]=v[i]-k;
        }
        if(!ok)
        {
            printf("no\n");
            continue;
        }
        if(n==1 && ok)
        {
            printf("yes\n");
            continue;
        }
        ok=0;
        for(int i=1;i<=n-2 && !ok;++i)
            if((v[i]>=0 && v[i+1]>=0) || (v[i]>=0 &&v[i+2]>=0))
                ok=1;
        if(v[n-1]>=0 && v[n]>=0)
            ok=1;
        if(!ok)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}