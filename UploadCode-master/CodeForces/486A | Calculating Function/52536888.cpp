#include <iostream>
using namespace std;
int main()
{
   long long int x,y;
   cin>>x;
   if(x%2==0)
      cout<<x/2;
   else
      cout<<-(x+1)/2;
}