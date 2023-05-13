#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int n;
 cin>>n;
 string s;
 cin>>s;
 long long int count = 0;
 for(long long int i=0;i<s.size();)
 {
  if(s[i] == s[i+1])
  {
   s.erase(s.begin()+i+1);
   count++;
  }
  else if(i == s.length()-1)
  {
   count++;
   s.erase(s.begin()+i);
   break;
  }
  else
   i = i+2;
 }
 cout<<count<<endl;
 cout<<s;
}