#include <bits/stdc++.h>
using namespace std;
const int NMax = 1e5 + 5;
int N,nrSol;
int v[NMax],sol[NMax],pre[NMax];
ifstream in("scmax.in");
ofstream out("scmax.out");
void print(int x)
{
     if (x == 0)
         return;
     print(pre[x]);
     out<<v[x]<<' ';
}
int main()
{
    in>>N;
    nrSol = 0;
    for (int i=1;i <= N;++i)
    {
        in>>v[i];
        int pos = 0,put;
        for (put = 1;put <= nrSol;put <<= 1) ;
        put >>= 1;
        while (put)
        {
            if (pos + put <= nrSol && v[sol[pos + put]] <= v[i])
                pos += put;
            put >>= 1;
        }
        if (v[sol[pos]] == v[i])
            continue;
        sol[pos+1] = i;
        pre[i] = sol[pos];
        if (pos == nrSol)
            ++nrSol;
    }
    out<<nrSol<<'\n';
    print(sol[nrSol]);
    in.close();
    out.close();
    return 0;
}