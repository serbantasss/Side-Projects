#include <fstream>
using namespace std;
int v[100001],a[100001];
int main ()
{
    ifstream in ("numarare.in");
    ofstream out ("numarare.out");
    int n,i,p,suma;
    in>>n>>v[1];
    for (i=2;i<=n;i++)
    {
        in>>v[i];
        v[i-1]-=v[i];
    }
    suma=n-1;
    p=1;
    for (i=1;i<n;i++)
    {
        if (i<p+a[p])
        {
            if (a[2*p-i]<=p+a[p]-i)
                a[i]=a[2*p-i];
            else
                a[i]=p+a[p]-i;
        }
        if (i+a[i]>=p+a[p])
        {
            p=i;
            while (i-a[i]-1>=1 && i+a[i]+1<=n && v[i-a[i]-1]==v[i+a[i]+1])
                a[i]++;
        }
    }
    for (i=1;i<n;i++)
        suma+=a[i];
    out<<suma<<"\n";
    return 0;
}