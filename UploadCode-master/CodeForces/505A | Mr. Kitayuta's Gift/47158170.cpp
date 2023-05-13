#include <iostream>
#include <cstring>
 
using namespace std;
 
string s,cs,y;
 
bool ok(string x)  {
  for (int i=0; i<x.size();i++)  {
    if (x[i]!=x[x.size()-i-1])
      return false;
  }
  return true;
}
 
int main()  {
  cin>>s;
  for (int i=0;i<=s.size();i++)  {
    for (int j=0;j<26;++j)  {
      cs=s;
      y=('a'+j);
      cs.insert(i,y);
      if (ok(cs))  {
        cout<<cs<<'\n';
        return 0;
      }
    }
  }
  cout << "NA";
  return 0;
}