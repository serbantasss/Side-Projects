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
long long v[200005];
bool semn[200005];
char s[20];
int main(int argc, const char * argv[])
{
    //    freopen("cover1.in","r",stdin);
    //    freopen("cover1.out","w",stdout);
    long long n,k,i,j,a,b,c,cnt;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;++i)
    {
        scanf("\n%s",s);
        if(s[0]=='?')
            semn[i]=1;
        else
            v[i]=stoi(s);
        //printf("%lld ",v[i]);
    }
    for(i=1;i<=k;++i)
    {
        a=-LLONG_MAX;
        cnt=0;
        for(j=i;j<=n;j+=k)
        {
            if(semn[j])
                cnt++;
            else
                if(cnt)
                {
                    b=v[j]-cnt;
                    if(b<a && cnt)
                    {
                        printf("Incorrect sequence\n");
                        return 0;
                    }
                    if(b>0 && 0>a)
                    {
                        c=-(cnt/2);
                        while(c<=a)
                            c++;
                    }
                    else
                        if(a>=0)
                            c=a+1;
                        else
                            if(b<=0)
                                c=b;
                    if(j>=cnt*k)
                        for(int q=j-cnt*k;semn[q];q+=k,c++)
                            v[q]=c;
                    cnt=0;
                    a=v[j];
                }
                else
                    a=v[j];
        }
        if(cnt)
        {
            b=LLONG_MAX;
            if(b<a && cnt)
            {
                printf("Incorrect sequence\n");
                return 0;
            }
            if(b>0 && 0>a)
            {
                c=-(cnt/2);
                while(c<=a)
                    c++;
            }
            else
                if(a>=0)
                    c=a+1;
                else
                    if(b<=0)
                        c=b;
            if(j>=cnt*k)
                for(long long q=j-cnt*k;semn[q];q+=k,c++)
                    v[q]=c;
        }
    }
    for(i=1;i<=k;++i)
        for(j=i+k;j<=n;j+=k)
            if(v[j]<=v[j-k])
            {
                printf("Incorrect sequence\n");
                return 0;
            }
    for(i=1;i<=n;++i)
        printf("%lld ",v[i]);
    return 0;
}