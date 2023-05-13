#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[100001],b[100001];
int main()
{
    ifstream in("permut.in");
    ofstream out("permut.out");
    int n,i,j;
    in>>n;
    for(i=1;i<=n;++i)
        in>>a[i];
    for(i=1;i<=n;++i)
        in>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    long long int s=0;
    for(i=1;i<=n;++i)
        s=s+(long long int)a[i]*b[i];
    out<<s;
    return 0;
}