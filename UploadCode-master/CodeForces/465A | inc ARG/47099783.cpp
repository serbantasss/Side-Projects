#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    int n, res = 0;
    string s;
    cin >> n >> s;
    for (int i  = 0; i < n; i++)
    {
        if (s[i] == '1') res++;
        else
        {
            res++;
            break;
        }
    }
    cout << res;
}