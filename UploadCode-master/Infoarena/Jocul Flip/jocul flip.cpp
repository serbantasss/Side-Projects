#include <fstream>
using namespace std;

ifstream is("flip.in");
ofstream os("flip.out");

int s, t, n, m, smax;
int a[17][17];
int x[17];

void Back_Solve(int k);

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            is >> a[i][j];
    Back_Solve(1);
    os << smax;
    is.close();
    os.close();
    return 0;
}

void Back_Solve(int k)
{
    if ( k == m + 1 )
    {
        s = 0;
        for ( int i = 1; i <= n; ++i )
        {
            t = 0;
            for ( int j = 1; j <= m; ++j )
                if ( x[j] )
                    t -= a[i][j];
                else
                    t += a[i][j];
            s += max(t, -t);
        }
        smax = max(smax, s);
        return;
    }

    x[k] = 0;
    Back_Solve(k + 1);
    x[k] = 1;
    Back_Solve(k + 1);
}