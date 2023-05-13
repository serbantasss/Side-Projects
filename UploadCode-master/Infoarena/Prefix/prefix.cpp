#include <bits/stdc++.h>
using namespace std;
int regula[1000005];
int main()
{
    ifstream in("prefix.in");
    ofstream out("prefix.out");
    int t;
    in>>t;
    while(t--)
    {
        int n,i,k=0,ans=0;
        string s;
        in>>s;
        n=s.size();
        for(i=1;i<n;++i)
        {
            k=i-1;
            while(regula[k] && s[regula[k]]!=s[i])
                k=regula[k]-1;
            if(s[regula[k]]==s[i])
                regula[i]=regula[k]+1;
            else
                regula[i]=0;
        }
        for(i=0;i<n;++i)
            if(regula[i] && (i+1)%(i+1-regula[i])==0)
                ans=i+1;
        out<<ans<<"\n";
        ///init
        for(i=0;i<=1000000;++i)
            regula[i]=0;
    }
    return 0;
}