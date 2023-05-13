#include <bits/stdc++.h>
using namespace std;
int v[3];
int main()
{
//    freopen("cabana.in","r",stdin);
//    freopen("cabana.out","w",stdout);
    scanf("%d%d%d",&v[0],&v[1],&v[2]);
    sort(v,v+3);
    if(v[0]+v[1]>v[2])
        printf("0");
    else
        printf("%d",v[2]-v[0]-v[1]+1);
    return 0;
}