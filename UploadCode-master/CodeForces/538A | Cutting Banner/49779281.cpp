#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i= int(a);i<=int(b);i++)
 
int main()
{
 string x;
 cin>>x;
 string s("CODEFORCES");
 int a,b,flag=0;
 if(x.size()<=s.size())
  flag=0;
 else if(x.find(s)==0 || x.find(s)==x.size()-10)
  flag=1;
 else
 {
  F(i,1,s.size()-1)
  {
   a=(x.substr(0,i)).find(s.substr(0,i));
   b=(x.substr(x.size()-10+i)).find(s.substr(i));
   
   if((a==0) && b==0)
   {
    flag=1;
    break;
   }
  }
 }
 
 if(flag==1)
  cout<<"YES"<<"\n";
 else
  cout<<"NO"<<"\n";
}