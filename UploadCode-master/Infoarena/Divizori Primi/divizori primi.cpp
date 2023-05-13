#include <fstream>

using namespace std;

ifstream fi ("divprim.in");
ofstream fo ("divprim.out");


bool sieve[1000005];
int P[80000],h;
short int sol[1000005];
int M[1000005][10];


inline void ciur()
{
    sieve[0] = sieve[1] = 1;
    for(int i=4; i<=1000000; i+=2)
        sieve[i]=1;
    for(int i=3; i<=1000; i+=2)
        if (! sieve[i] )
            for(int j=i*i; j<=1000000; j+=( i<<1 ))
                sieve[j]=1;
    P[1]=2;
    h=1;
    for(int i=3; i<=1000000; i+=2)
        if (! sieve [i])
            P[++h]=i;

    for(int i=1; i<=h; ++i)
        for(int j=P[i]; j<=1000000; j+=P[i])
            ++sol[j];
}
inline void solve()
{
    ciur();
    for(int i=1; i<=1000000; ++i)
        for(int j=1; j<=7; ++j)
        {
            if (sol[i]==j)
                M[i][j]=i;
            else
                M[i][j]=M[i-1][j];
        }
}
int main()
{
    int T,N,K;
    fi >> T;
    solve();
    for ( ; T ; --T)
    {
        fi >> N >> K;
        fo << M[N][K] << "\n";
    }
    return 0;
}