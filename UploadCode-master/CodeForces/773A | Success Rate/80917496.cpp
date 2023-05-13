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
using namespace std;
long long foca_bag_ceva_in_xcode(long long a,long long b)
{
    return (a+b-1)/b;
}
int main(int argc, const char * argv[])
{
//    freopen("cover1.in","r",stdin);
//    freopen("cover1.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,y,p,q,k;
        scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
        if(p==0)
        {
            if(x==0)
                printf("0\n");
            else
                printf("-1\n");
            continue;
        }
        if(p==q)
        {
            if(x==y)
                printf("0\n");
            else
                printf("-1\n");
            continue;
        }
        k=max(foca_bag_ceva_in_xcode((y-x),(q-p)),foca_bag_ceva_in_xcode(x, p));
        printf("%lld\n",k*q-y);
    }
    return 0;
}