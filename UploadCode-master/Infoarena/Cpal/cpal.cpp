#include<fstream>
using namespace std;
int main()
{
    ifstream in("cpal.in");
    ofstream out("cpal.out");
    int t=10,f,nr,p;
    while(t--)
    {
        nr=0;
        p=0;
        for(int i=1;i<=9;i++)
        {
            in>>f;
            if(f)
                p=1;
            nr+=f%2;
        }
        if(nr<2&&p)
            out<<1<<'\n';
        else
            out<<0<<'\n';
    }
    return 0;
}