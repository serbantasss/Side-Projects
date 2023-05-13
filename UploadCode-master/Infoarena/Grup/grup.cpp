//
//  main.cpp
//  grup
//
//  Created by Serban Bantas on 23/01/2020.
//  Copyright © 2020 Serban Bantas. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <climits>
#include <ctime>
#include <vector>
using namespace std;
long long v[100005];
bool b1[100005],b2[100005];
vector<long long> peasant;
vector<long long> dusman;
vector<long long> prieten;
vector<long long> barosan;
int main(int argc, const char * argv[]) {
    int start=clock();
    freopen("grup.in","r",stdin);
    freopen("grup.out","w",stdout);
    long long n,s,k1,k2,suma=0,ans=LLONG_MAX;
    char ch;
    scanf("%lld%lld%lld%lld",&n,&s,&k1,&k2);
    for(int i=1;i<=n;++i)
        scanf("%lld",&v[i]);
    scanf("\n");
    for(int i=1;i<=n;++i)
    {
        scanf("%c",&ch);
        b1[i]=ch-'0';
    }
    scanf("\n");
    for(int i=1;i<=n;++i)
    {
        scanf("%c",&ch);
        b2[i]=ch-'0';
        if(b1[i]==0)
        {
            if(b2[i]==0)
                peasant.push_back(v[i]);
            if(b2[i]==1)
                dusman.push_back(v[i]);
        }
        else
        {
            if(b2[i]==0)
                prieten.push_back(v[i]);
            if(b2[i]==1)
                barosan.push_back(v[i]);
        }
    }
    sort(dusman.begin(),dusman.end());
    sort(barosan.begin(),barosan.end());
    sort(peasant.begin(),peasant.end());
    sort(prieten.begin(),prieten.end());
    long long i0=0,i1=0,i2=0,i3=-1;
    k2=s-k2;
    for(i3=-1;i3<=s && i3<(int)prieten.size();)
    {
        if(i3==-1)
            i3++;
        else
            suma+=prieten[i3++];
        if(k1-i3>(int)barosan.size())
            continue;
        if(k2-i3>(int)peasant.size())
            continue;
        if(k1+k2-i3>s)
            continue;
        if(i3+(int)dusman.size()+(int)barosan.size()+(int)peasant.size()<s)
            continue;
        if(i0>0)
            suma-=dusman[--i0];
        if(i1>0)
            suma-=barosan[--i1];
        if(i2>0)
            suma-=peasant[--i2];
        while(i3+i1<k1)
            suma+=barosan[i1++];
        while(i3+i2<k2)
            suma+=peasant[i2++];
        while(i0+i1+i2+i3<s)
        {
            if(i0<(int)dusman.size() && i1<(int)barosan.size() && i2<(int)peasant.size())
            {
                if(dusman[i0]<barosan[i1] && dusman[i0]<peasant[i2])
                {
                    suma+=dusman[i0++];
                    continue;
                }
                if(barosan[i1]<dusman[i0] && barosan[i1]<peasant[i2])
                {
                    suma+=barosan[i1++];
                    continue;
                }
                if(peasant[i2]<barosan[i1] && dusman[i0]>peasant[i2])
                {
                    suma+=peasant[i2++];
                    continue;
                }
            }
            if(i0<(int)dusman.size() && i1<(int)barosan.size())
            {
                if(dusman[i0]<barosan[i1])
                {
                    suma+=dusman[i0++];
                    continue;
                }
                else
                {
                    suma+=barosan[i1++];
                    continue;
                }
            }
            if(i0<(int)dusman.size() && i2<(int)peasant.size())
            {
                if(dusman[i0]>peasant[i2])
                {
                    suma+=peasant[i2++];
                    continue;
                }
                else
                {
                    suma+=dusman[i0++];
                    continue;
                }
            }
            if(i1<(int)barosan.size() && i2<(int)peasant.size())
            {
                if(barosan[i1]>peasant[i2])
                {
                    suma+=peasant[i2++];
                    continue;
                }
                else
                {
                    suma+=barosan[i1++];
                    continue;
                }
            }
            if(i0<(int)dusman.size())
            {
                suma+=dusman[i0++];
                continue;
            }
            if(i1<(int)barosan.size())
            {
                suma+=barosan[i1++];
                continue;
            }
            if(i2<(int)peasant.size())
            {
                suma+=peasant[i2++];
                continue;
            }
        }
        ans=min(ans,suma);
    }
    printf("%lld\n",ans);
    int end=clock();
    //printf("%lf",((float)end - start)/CLOCKS_PER_SEC);
    return 0;
}