#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("bete2.in");
ofstream cout("bete2.out");
int v[3005];
int main()
{
    int n,i,j,k,st,dr,mid;
    long long int sol=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    for(i=1;i<=n-2;++i)
        for(j=i+1;j<=n-1;++j)
        {
            st=j+1;
            dr=n;
            while(st<=dr)
            {
                mid=(st+dr)/2;
                if(v[mid]==v[i]+v[j])
                {
                    sol++;
                    break;
                }
                if(v[mid]>v[i]+v[j])
                {
                    dr=mid-1;
                }
                else
                    st=mid+1;
            }
        }
    cout<<sol;
    return 0;
}