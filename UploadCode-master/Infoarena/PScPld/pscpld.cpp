#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

long long n,f[2000005],l=0,rez=-1,k;
char a[1000005];
vector<char>v;

int main()
{
    ifstream cin("pscpld.in");
    ofstream cout("pscpld.out");
    cin>>(a+1);
    int n=strlen(a+1);
    for(long long i=1;i<=n;i++){
        v.push_back('*');
        v.push_back(a[i]);
    }
    v.push_back('*');
    int len=v.size();
    for (long long i=0;i<len;i++){
        if(i>rez)
            k=0;
        else
            k=min(f[l+rez-i],rez-i);
        while (i+k<len and i-k>=0 and v[i+k]==v[i-k])
            k++;
        f[i]=k;
        k--;
        if (i+k>rez){
            l=i-k;
            rez=i+k;
        }
    }
    long long ans=strlen(a+1);
    for(long long i=0;i<len;i++){
        ans+=(f[i]-1);
    }
    cout<<ans/2;
}