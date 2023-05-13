//
//  main.cpp
//  lgput
//
//  Created by Serban Bantas on 22/02/2020.
//  Copyright © 2020 Serban Bantas. All rights reserved.
//

#include <cstdio>
using namespace std;
const int n_max = 10001; // Definim numarul maxim de cifre al numerelor
const int m = 666013;
int solo[3][3],M[3][3];
void inmultaa()
{
    int c[3][3];
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
void inmultsola()
{
    int c[3][3];
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
    freopen("kfib.in","r",stdin);
    freopen("kfib.out","w",stdout);
    unsigned int i, n, p;
    long long a, sol = 1;
    scanf("%d", &n);
    M[0][0]=0;
    M[0][1]=1;
    M[1][0]=1;
    M[1][1]=1;
    solo[0][0]=solo[1][1]=1;
    for (i = 0; (1<<i) <= n; ++ i)  // Luam toti biti lui p la rand
    {
        if ( ((1<<i) & n) > 0) // Daca bitul i din p este 1 atunci adaugam n^(2^i) la solutie
            inmultsola();
        
        inmultaa(); // Inmultim a cu a ca sa obtinem n^(2^(i+1))
    }
    printf("%d",solo[0][1]);
    return 0;
}