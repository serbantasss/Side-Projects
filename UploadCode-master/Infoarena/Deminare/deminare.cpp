//
//  main.cpp
//  deminare
//
//  Created by Serban Bantas on 24/01/2020.
//  Copyright © 2020 Serban Bantas. All rights reserved.
//

#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int mat[505][505];
int main(int argc, const char * argv[]) {
    freopen("deminare.in","r",stdin);
    freopen("deminare.out","w",stdout);
    int n,m,b,i,j;
    int test;
    scanf("%d",&test);
    scanf("%d%d%d",&n,&m,&b);
    for(i=1;i<=b;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        mat[x][y]=1;
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            mat[i][j]=mat[i][j]+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
    if(test==1)
    {
        int ma=mat[1][m];
        for(i=2;i<=n;++i)
            if(ma<mat[i][m]-mat[i-1][m])
                ma=mat[i][m]-mat[i-1][m];
        for(i=1;i<=n;++i)
            if(ma==mat[i][m]-mat[i-1][m])
                printf("%d ",i);
    }
    else
    {
        int ans=INT_MAX;
        for(int l=1;l<=n;++l)
            for(int c=1;c<=m;++c)
                if(l*c==b)
                {
                    for(i=l;i<=n;++i)
                        for(j=c;j<=m;++j)
                            ans=min(ans,b-(mat[i][j]-mat[i-l][j]-mat[i][j-c]+mat[i-l][j-c]));
                }
        if(ans==INT_MAX)
            printf("-1");
        else
            printf("%d",ans);
    }
    return 0;
}