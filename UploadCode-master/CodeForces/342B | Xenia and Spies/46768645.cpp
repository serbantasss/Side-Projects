#include <bits/stdc++.h>
 
using namespace std;
struct intt
{
    int step,l,r;
} v[100005];
int main()
{
    int n,m,s,f,i,j,x,pas,dir;
    scanf("%d%d%d%d",&n,&m,&s,&f);
    if(s<f)
        dir=1;
    else
        dir=-1;
    for(i=1; i<=m; ++i)
    {
        scanf("%d",&x);
        v[i].step=x;
        scanf("%d",&x);
        v[i].l=x;
        scanf("%d",&x);
        v[i].r=x;
    }
    i=1;
    pas=1;
    int curr=s;
    while(1)
    {
        if(pas>v[m].step)
        {
            for(i=1; i<=abs(f-curr); ++i)
                if(dir==1)
                    printf("R");
                else
                    printf("L");
            return 0;
        }
        if(pas==v[i].step)
        {
            if(curr<v[i].l || curr>v[i].r)
            {
                if(curr==1 && (2<v[i].l || 2>v[i].r))
                {
                    curr+=dir;
                    if(dir==1)
                        printf("R");
                    else
                        printf("L");
                }
                else if(curr==n && (n-1<v[i].l || n-1>v[i].r))
                {
                    curr+=dir;
                    if(dir==1)
                        printf("R");
                    else
                        printf("L");
                }
                else if(curr+dir<v[i].l || curr+dir>v[i].r)
                {
                    curr+=dir;
                    if(dir==1)
                        printf("R");
                    else
                        printf("L");
                }
                else
                    printf("X");
            }
            else
                printf("X");
            i++;
        }
        else
        {
            curr+=dir;
            if(dir==1)
                printf("R");
            else
                printf("L");
        }
        if(curr==f)
        {
            return 0;
        }
        pas++;
    }
    return 0;
}