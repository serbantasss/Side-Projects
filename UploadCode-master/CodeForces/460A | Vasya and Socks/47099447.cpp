#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int i=0;
    while(n!=0)
    {
        if(i%m==0)
            n++;
        i++;
        n--;
 
    }
    cout<<i-1;
    return 0;
}