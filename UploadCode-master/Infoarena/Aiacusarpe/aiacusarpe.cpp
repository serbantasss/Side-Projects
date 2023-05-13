//
//  main.cpp
//  aiacusarpe
//
//  Created by Serban Bantas on 28/02/2020.
//  Copyright © 2020 Serban Bantas. All rights reserved.
//

#include <bits/stdc++.h>
#define x first
#define y second
#define max(a, b) ((a > b) ? a : b)
using namespace std;
bool viz[1005][1005];
int n,m,t,f,lmax=0;
queue<pair<int,int> > poz;
int main(int argc, const char * argv[])
{
    freopen("aiacusarpe.in","r",stdin);
    freopen("aiacusarpe.out","w",stdout);
    scanf("%d%d%d\n",&n,&m,&t);
    int px=1,py=1;
    poz.push({px,py});
    viz[px][py]=1;
    for(int i=0;i<t;++i)
    {
        char ch;
        scanf("%c",&ch);
        if(ch=='N')
            px--;
        if(ch=='S')
            px++;
        if(ch=='V')
            py--;
        if(ch=='E')
            py++;
        if(px<1 || px>n || py<1 || py>m)
            break;
        if(viz[px][py])
        {
            while(poz.front().x!=px || poz.front().y!=py)
            {
                viz[poz.front().x][poz.front().y]=0;
                poz.pop();
            }
            poz.pop();
            poz.push({px,py});
            lmax=max(poz.size(),lmax);
        }
        else
        {
            viz[px][py]=1;
            poz.push({px,py});
            lmax=max(poz.size(),lmax);
        }
    }
    printf("%d",lmax);
    return 0;
}