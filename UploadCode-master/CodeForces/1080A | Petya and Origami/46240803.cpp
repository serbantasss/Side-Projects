#include <iostream>
 
using namespace std;
 
 
int main()
{
 
    int n,k,i;
    cin>>n>>k;
    int nrred,nrgreen,nrblue;
    nrred = n*2;
    nrgreen = n*5;
    nrblue = n*8;
    int nrcaiete=0;
    nrcaiete = nrred/k + nrblue/k + nrgreen/k;
    if(nrred%k!=0)
        nrcaiete++;
    if(nrblue%k!=0)
        nrcaiete++;
    if(nrgreen%k!=0)
        nrcaiete++;
    cout<<nrcaiete;
    return 0;
}