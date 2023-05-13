#include <iostream>
using namespace std;
int main()
{
    double r,h;
    cin>>r>>h;
    int d=(h+0.5*r)/r;
    cout<<(int)((h+r-d*r)*1.154701/r)+d*2;
    return 0;
}