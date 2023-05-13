#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    scanf("%d%d%d",&a,&b,&c);
    a=a-x;
    b=b+a;
    b=b-y;
    if(a>=0 && b>=0 && z<=b+c)
        printf("YES");
    else
        printf("NO");
    return 0;
}