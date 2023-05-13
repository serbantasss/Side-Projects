#include <iostream>
 
using namespace std;
int v[10005];
int main()
{
    int n,i,j,ma,day=0,page=1;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    ma=v[page];
    while(page<=n)
    {
        if(page==ma)
        {
            day++;
            page++;
            ma=v[page];
        }
        else
            {page++;
            if(ma<v[page])
                ma=v[page];}
    }
    cout<<day;
    return 0;
}