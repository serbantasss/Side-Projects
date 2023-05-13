//
//  main.cpp
//  lgput
//
//  Created by Serban Bantas on 22/02/2020.
//  Copyright © 2020 Serban Bantas. All rights reserved.
//

#include <cstdio>
using namespace std;
const int m = 1000000007;
int solo[2][2],M[2][2];
void inmultMM()
{
    int c[2][2];
    c[0][0]=0;
    c[1][0]=0;
    c[1][1]=0;
    c[0][1]=0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c[i][j] = (c[i][j] + 1LL * M[i][k] * M[k][j]) % m;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            M[i][j]=c[i][j];
}
void inmultsolM()
{
    int c[2][2];
    c[0][0]=0;
    c[1][0]=0;
    c[1][1]=0;
    c[0][1]=0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c[i][j] = (c[i][j] + 1LL * solo[i][k] * M[k][j]) % m;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            solo[i][j]=c[i][j];
}
int main(int argc, const char * argv[])
{
        freopen("aiafarapalindroame.in","r",stdin);
        freopen("aiafarapalindroame.out","w",stdout);
    unsigned int i, n, p;
    long long a, sol = 1;
    scanf("%d", &n);
    if(n==1)
    {
        printf("26");
        return 0;
    }
    if(n==2)
    {
        printf("676");
        return 0;
    }
    M[0][0]=24;
    M[0][1]=1;
    M[1][0]=24;
    M[1][1]=0;
    solo[1][1]=1;
    solo[0][0]=1;
    n-=3;
    for (i = 0; (1<<i) <= n; ++ i)  // Luam toti biti lui p la rand
    {
        if ( ((1<<i) & n) > 0) // Daca bitul i din p este 1 atunci adaugam n^(2^i) la solutie
            inmultsolM();
        
        inmultMM(); // Inmultim a cu a ca sa obtinem n^(2^(i+1))
    }
    
    int c[2][2];
    M[0][0]=16250;
    M[1][0]=0;
    M[0][1]=650;
    M[1][1]=0;
    c[0][0]=0;
    c[1][0]=0;
    c[1][1]=0;
    c[0][1]=0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c[i][j] = (c[i][j] + 1LL * M[i][k] * solo[k][j]) % m;
    printf("%d",(c[0][0]+c[0][1])%m);
    return 0;
}