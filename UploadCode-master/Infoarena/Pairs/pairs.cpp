//
//  main.cpp
//  pairs
//
//  Created by Serban Bantas on 29/11/2019.
//  Copyright © 2019 Serban Bantas. All rights reserved.
//
 
#include <bits/stdc++.h>
using namespace std;
const int nmax=1000005;
int cateprime[nmax];
bool mmprime[nmax],f[nmax];
void ciur()
{
    for(int i=2;i<=nmax;i++)
        if(!cateprime[i])
            for(int j=i;j<=nmax;j=j+i)
            {
                if(j%(i*i)==0)
                    mmprime[j]=1;
                cateprime[j]++;
            }
}
int main(int argc, const char * argv[])
{
    freopen("pairs.in","r",stdin);
    freopen("pairs.out","w",stdout);
    int n,i,maxi=0;
    long long ans=0;
    ciur();
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        f[x]=1;
        if(x>maxi)
            maxi=x;
    }
    for(i=2;i<=maxi;++i)
        if(mmprime[i]==0)
        {
            long long cnt=0;
            for(int j=i;j<=maxi;j+=i)
                if(f[j])
                    cnt++;
            if(cateprime[i]%2==0)
                ans-=1LL*cnt*(cnt-1)/2;
            else
                ans+=1LL*cnt*(cnt-1)/2;
        }
     ans=1LL*n*(n-1)/2-ans;
    printf("%lld",ans);
    return 0;
}