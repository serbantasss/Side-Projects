#include <cstdio>
using namespace std;
const int nmax=100005;
int tata[nmax],rang[nmax];
int gasestetata(int nod)
{
    int tatasuprem=nod;
    while(tata[tatasuprem]!=tatasuprem)
        tatasuprem=tata[tatasuprem];
    while(tata[nod]!=nod)///scurtare drum
    {
        int aux=tata[nod];
        tata[nod]=tatasuprem;
        nod=aux;
    }
    return tatasuprem;
}
void ceapa(int a,int b)//ceapa....onion....union...haha....flotari
{
    if(rang[a]<rang[b])
        tata[a]=b;
    else
        tata[b]=a;
    if(rang[a]==rang[b])
        rang[a]++;
}
int main()
{
    freopen("disjoint.in","r",stdin);
    freopen("disjoint.out","w",stdout);
    int n,i,q;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i)//init noduri
        tata[i]=i,rang[i]=1;
    for(i=1;i<=q;++i)//queries
    {
        int op,a,b;
        scanf("%d%d%d",&op,&a,&b);
        if(op==1)
            ceapa(gasestetata(a),gasestetata(b));
        else
            if(gasestetata(a)==gasestetata(b))
                printf("DA\n");
            else
                printf("NU\n");
    }
    return 0;
}