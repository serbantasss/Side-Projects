#include <iostream>
 
using namespace std;
 
int main()
{
    int n,k;
    cin>>n>>k;
    int i,j;
    if(n==1 && k==0)
    {
        cout<<1;
        return 0;
    }
    if(k<n/2 || n==1)
    {
        cout<<"-1";
        return 0;
    }
    else
    {
        int tot = n/2;
        int p = 1;
        if(n%2==1)
            p = 1;
        else
            p = 0;
        int sum=0;
        for(i=2;i<=n-1-p;i++)
        {
            cout<<i<<" ";
            if(i%2==0)
                sum++;
        }
        tot = sum*2+1;
        k=k-sum;
        int pol = tot/k;
        cout<<(pol+1)*k<<" "<<(pol+2)*k;
        if(n%2==1)
            cout<<" "<<1;
    }
    return 0;
}