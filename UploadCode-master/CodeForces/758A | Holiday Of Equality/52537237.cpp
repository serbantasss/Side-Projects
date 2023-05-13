#include <iostream>
using namespace std;
int v[1005];
int main()
{
   int n,i,max=0;
   long long s=0;
   cin>>n;
   for(i=1;i<=n;++i)
   {
      cin>>v[i];
      if(v[i]>max)
         max=v[i];
   }
   for(i=1;i<=n;++i)
   {
      s=s+max-v[i];
   }
   cout<<s;
   return 0;
}