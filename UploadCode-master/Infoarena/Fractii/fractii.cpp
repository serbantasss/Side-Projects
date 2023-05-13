#include <iostream>
#include <climits>
#include <cmath>
#include <fstream>
#define MAX 1000004
using namespace std;

int auxiliary[MAX];
int prime[MAX];

void init(long long n){

    for (long long i = 2; i <= n; i++){
        auxiliary[i] = 1;
        prime[i] = i;
    }
}

void prime_numbers(long long n){

    for (long long i = 2; i <= n; i++){
        if (auxiliary[i] == 1){

            prime[i] = i-1;
            for (long long j = i*2; j <= n; j = j + i){
                auxiliary[j] = 0;
                prime[j] = prime[j] * (i-1)/i;
            }
        }
    }

    return ;
}


long long number_of_fractions(long long n){
    long long contor = 0;

    for (long long i = 2; i <= n; i++){
        contor += prime[i];
    }
    return (contor * 2 + 1);

}

int main(void){


    long long result = 0;
    long long n;

    ifstream in;
    ofstream out;

    in.open("fractii.in");
    out.open("fractii.out");

    in >> n;
    init(n);
    prime_numbers(n);
    result = number_of_fractions(n);

    out << result;

     in.close();
    out.close();
    return 0;
}