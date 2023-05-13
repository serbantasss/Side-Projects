#include<cstdio>
#include<bitset>
#include<algorithm>
#include<queue>
#define x first
#define y second
using namespace std;
bitset<10005>m[10005],viz[10005];
pair<int,int> pad[16005];
queue<pair<int,int> >q;
int zone[16005];
int dx[]={0,-1,0,1,0},dy[]={0,0,1,0,-1};
int main()
{
    freopen("banana.in","r",stdin);
    freopen("banana.out","w",stdout);
    int n,k,rez=0,nr=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&pad[i].x,&pad[i].y);
        m[pad[i].x][pad[i].y]=1;
    }
    for(int i=1;i<=n;i++)
        if (viz[pad[i].x][pad[i].y]==0)
        {
            q.push(make_pair(pad[i].x,pad[i].y));
            int ban=0;
            while(!q.empty())
            {
                pair<int,int> nod2,nod=q.front();
                viz[nod.x][nod.y]=1;
                ban++;
                for(int j=1;j<=4;j++)
                {
                    nod2.x=nod.x+dx[j];
                    nod2.y=nod.y+dy[j];
                    if (m[nod2.x][nod2.y]==1 && viz[nod2.x][nod2.y]==0)
                    {
                        q.push(nod2);
                        viz[nod2.x][nod2.y]=1;
                    }
                }
                q.pop();
            }
            zone[++nr]=ban;
        }
    sort(zone+1,zone+nr+1);
    for(int i=nr;i>=nr-k+1;i--)
        rez=rez+zone[i];
    printf("%d\n",rez);
    return 0;
}