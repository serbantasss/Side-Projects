#include <bits/stdc++.h>







using namespace std;







ifstream fin("inundatie.in");



ofstream fout("inundatie.out");







int n , m , a[90005] , q;



long long s[90005];







void cautbin(int x)



{



    if(x <= 0)



    {



        fout << 0 <<"\n";



        return;



    }



    int st = 1, dr = n , mij , poz = 0;



    while(st <= dr)



    {



        mij = (st + dr) / 2;



        if(a[mij] <= x)



        {



            poz = mij;



            st = mij + 1;



        }



        else dr = mij - 1;



    }



    fout << s[poz] + 1LL * x * (n - poz) << "\n";



}



int main()



{



    int y;



    fin >> n >> m;



    n *= m;



    for(int i = 1; i <= n; i++)



        fin >> a[i];







    sort(a + 1, a + n + 1);







    for(int i = 1; i <= n; i++)



        s[i] = s[i - 1] + a[i];



    fin >> q;



    for(int i = 1; i <= q; i++)



    {



        fin >> y;



        cautbin(y - 1);



    }







    return 0;



}