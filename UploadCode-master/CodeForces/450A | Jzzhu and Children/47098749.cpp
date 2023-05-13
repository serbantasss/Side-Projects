#include <bits/stdc++.h>
using namespace std;
int main()
{
 long long int n,q;
 cin>>n>>q;
 long long int a[n],m=0,pos;
 for (int i = 0; i < n; ++i)
 {
  cin>>a[i];
  if (m<=a[i])
  {
   m=a[i];
  }
 }
 if (q>=m)
 {
  cout<<n;
 }
 else
 {
  m=0;
  for (int i = 0; i < n; ++i)
  {
   a[i]=ceil((double)a[i]/(double)q);
   if (m<=a[i])
   {
       m=a[i];
    pos=i+1;
   }
  }
  cout<<pos;
 }
  return 0;
  }