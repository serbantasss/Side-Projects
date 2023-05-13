#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("staropramen.in");
    ofstream g("staropramen.out");
    int t, n, i, j, k, s, ct9;
    bool ok;
    char a, b;
    f>>t;
    for(i=1; i<=t; i++)
    {
        ct9=0;
        ok=true;
        f>>n;
        f>>a>>b;
        s=a+b-2*'0';
        for(j=2; j<=n; j++)
        {
            f>>a>>b;
            ok=true;
            if(a+b-2*'0'>=10 && ct9==0)
                s++;
            if(a+b-2*'0'==9)
            {
                ct9++;
                ok=false;
            }
            if(ct9==0)
                g<<s;
            else if(ok==true || j==n && ok==false)
            {
                if(a+b-2*'0'>=10)
                {
                    g<<s+1;
                    for(k=1; k<=ct9; k++)
                        g<<0;
                }
                else
                {
                    g<<s;
                    for(k=1; k<=ct9; k++)
                        g<<9;
                }
                ct9=0;
            }
            if(ct9==0)
                s=(a+b-2*'0')%10;
        }
        if(ok==true)
            g<<s;
        g<<endl;
    }
    f.close();
    g.close();
}