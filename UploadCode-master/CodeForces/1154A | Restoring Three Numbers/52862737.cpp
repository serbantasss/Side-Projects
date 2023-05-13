#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int a,b,c,d,ma;
   cin>>a>>b>>c>>d;
   ma=max(a,max(b,max(c,d)));
   if(ma==a)
   {
      cout<<ma-b<<" "<<ma-c<<" "<<ma-d;
   }
   else
   if(ma==b)
   {
      cout<<ma-a<<" "<<ma-c<<" "<<ma-d;
   }
   else
   if(ma==c)
   {
      cout<<ma-b<<" "<<ma-a<<" "<<ma-d;
   }
   else
   if(ma==d)
   {
      cout<<ma-b<<" "<<ma-c<<" "<<ma-a;
   }
   return 0;
}