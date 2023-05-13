#include <fstream>
using namespace std;
ifstream in("perechi.in");
ofstream out("perechi.out");
int main()
{
    int n,d,e,ans=1;
    in>>n;
    if(n>1)
    {
        d=2;
        while(n>1 && d*d<=n)
        {
            e=0;
            while(n%d==0)
                e++,n/=d;
            if(e>0)
            {
                ans=ans*(2*e+1);
            }
            d++;
        }
        if(n>1)
            ans=ans*(2*1+1);
    }
    ans=(ans+1)/2;
    out<<ans;
    return 0;
}