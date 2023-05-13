#include<bits/stdc++.h>
using namespace std;
int harta[255][255],n;
int harta2[255][255];
struct camera
{
    int st,dr,sus,jos;
    int area;
};
camera pb;
vector<camera> v;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void fyl(int x,int y)
{
    harta[x][y]=2;
    if(x%2==0 && y%2==0)
        pb.area++;
    if(x>pb.jos)
        pb.jos=x;
    if(x<pb.sus)
        pb.sus=x;
    if(y>pb.dr)
        pb.dr=y;
    if(y<pb.st)
        pb.st=y;
    for(int i=0;i<4;++i)
        if(!harta[x+dx[i]][y+dy[i]])
            fyl(x+dx[i],y+dy[i]);
}
void afis()
{
    for(int i=1;i<=2*n+1;++i)
    {
        for(int j=1;j<=2*n+1;++j)
            printf("%d",harta[i][j]);
        printf("\n");
    }
}
int main()
{
    freopen("castel3.in","r",stdin);
    freopen("castel3.out","w",stdout);
    int cer,x;
    scanf("%d%d",&cer,&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&x);
            if(x&1)
                harta[2*i-1][2*j-1]=harta[2*i][2*j-1]=harta[2*i+1][2*j-1]=1;
            if(x&2)
                harta[2*i+1][2*j-1]=harta[2*i+1][2*j]=harta[2*i+1][2*j+1]=1;
            if(x&4)
                harta[2*i-1][2*j+1]=harta[2*i][2*j+1]=harta[2*i+1][2*j+1]=1;
            if(x&8)
                harta[2*i-1][2*j-1]=harta[2*i-1][2*j]=harta[2*i-1][2*j+1]=1;
        }
    
    for(int i=0;i<=2*n+2;++i)
        harta[i][0]=harta[i][2*n+2]=harta[0][i]=harta[2*n+2][i]=1;
    for(int i=4;i<=2*n+1;++i)
        for(int j=4;j<=2*n+1;++j)
            if(!harta[i][j])
            {
                pb.sus=pb.st=2*n+1;
                pb.jos=pb.dr=0;
                pb.area=0;
                fyl(i,j);
                if(pb.sus%2==1 || pb.jos%2==1 || pb.st%2==1 || pb.dr%2==1)
                    continue;
                v.push_back(pb);
            }
    if(cer==1)
    {
        printf("%lu\n",v.size());
        return 0;
    }
    int ma=-1,ima = 0;
    for(int i=0;i<v.size();++i)
        if(ma<v[i].area)
        {
            ima=i;
            ma=v[i].area;
        }
    if(cer==3)
        printf("%d %d %d %d\n",v[ima].sus/2,v[ima].st/2,v[ima].jos/2,v[ima].dr/2);
    else
        printf("%d\n",v[ima].area);
    return 0;
}