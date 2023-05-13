#include <iostream>
using namespace std;
double poww(double x, int y)
{
    double ans = 1, base = x;
    while (y)
    {
        if (y & 1 != 0)
        {
            ans *= base;
        }
        base = base * base;
        y >>= 1;
    }
    return ans;
}
double m, a=0;
int n;
int main()
{
    cin >> m >> n;
    for (double i = 1; i <=m; i++)
        a=a+i*(poww(i/m,n)-poww((i-1)/m,n));
    cout << a;
    return 0;
}