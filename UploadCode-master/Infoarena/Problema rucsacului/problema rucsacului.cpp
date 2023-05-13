#include <cstdio>
 
const int N = 5010;
const int G_MAX = 10005;
 
int val[N],g[N],n;
int g_max;
int valoare[G_MAX];
 
void citire()
{
    scanf("%d%d",&n,&g_max);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d",&g[i],&val[i]);
}
 
void init_rucsac()
{
    valoare[0] = 0;
    for (int i = 1; i <= g_max; ++i)
        valoare[i] = -1;
}
 
void rucsac()
{
    init_rucsac();
    for (int o = 1; o <= n; ++o)
        if (val [o] > 0)
        for (int i = g_max - g[o]; i >= 0; --i)
            if ((valoare[i] != -1) && (valoare[i + g[o]] < valoare[i] + val[o]))
                valoare[i + g[o]] = valoare[i] + val[o];
}
 
int valoare_maxima()
{
    int val_max = 0;
    for (int i = 0; i <= g_max; ++i)
        if (valoare[i] > val_max)
            val_max = valoare[i];
    return val_max;
}
 
int main()
{
    freopen("rucsac.in","r",stdin);
    freopen("rucsac.out","w",stdout);
    citire();
    rucsac();
    printf("%d",valoare_maxima());
    return 0;
}