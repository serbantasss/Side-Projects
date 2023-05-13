#include <bits/stdc++.h>
 
using namespace std;
long long v[200005],n,p,q,temp;
long long verif(long long nod)
{
    long long sum=0,x;
    for(long long i=1; i<=n; i++)
    {
        x=(v[i]-q*nod)/(p-q);
        if((v[i]-q*nod)%(p-q)!=0)
            x++;
        x=max(x,(long long)0);
        if(x>nod)
            return 0;
        sum+=x;
    }
    if(sum>nod*temp)
        return 0;
    return 1;
}
int main()
{
    ifstream cin("butoaie.in");
    ofstream cout("butoaie.out");
    long long k,ma;
    cin>>n>>k>>p>>q;
    for(long long i=1; i<=n; i++)
    {
        cin>>v[i];
        ma=max(ma,v[i]);
    }
    if(p==q)
    {
        long long val=ma/p;
        if(ma%p!=0)
            val++;
        cout<<val;
        return 0;
    }
    else
    {
        if(p<q)
        {
            swap(p,q);
            temp=n-k;
        }
        else
            temp=k;
    }
    long long st=1,dr=1000000000,last=0;
    while(st<=dr)
    {
        long long mid=(st+dr)/2;
        if(verif(mid)==1)
        {
            last=mid;
            dr=mid-1;
        }
        else
            st=mid+1;
    }
    cout<<last;
    return 0;
}