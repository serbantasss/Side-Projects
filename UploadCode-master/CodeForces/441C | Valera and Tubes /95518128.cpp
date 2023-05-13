#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int x[100005], y[100005];
vector<pair<int,int> > v;
int main(void)
{
    int n,m,i,k,cnt=0,col=1,lin=1,dir=0;
    scanf("%d%d%d",&n,&m,&k);
    while(cnt<n*m)
    {
        if(dir==0)
        {
            if(col<=m)
            {
                v.push_back({lin,col});
                col++;
            }
            else
            {
                v.push_back({lin+1,col-1});
                lin++;col-=2;
                dir=1;
            }
        }
        else if(dir==1)
        {
            if(col>=1)
            {
                v.push_back({lin,col});
                col--;
            }
            else
                if(col==0)
                {
                    v.push_back({lin+1,col+1});
                    lin++;
                    col=2;
                    dir=0;
                }
        }
        cnt++;
    }
    for(i=0;i<k-1;i++)
        printf("2 %d %d %d %d\n",v[2*i].x,v[2*i].y,v[2*i+1].x,v[2*i+1].y);
    printf("%d ",n*m-2*(k-1));
    for(i=2*k-2;i<v.size();i++)
        printf("%d %d ",v[i].x,v[i].y);
    return 0;
}