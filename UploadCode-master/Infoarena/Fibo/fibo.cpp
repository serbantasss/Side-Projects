#include<cstdio>
#include<cstring>
#include<bitset>

using namespace std;

#define DIM 37

int N, M=30, sol=1;

int fib[] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269,2178309,3524578,5702887,9227465,14930352};

inline int verif(int val) {
    int max=0;
 register int i=M;
 bitset <DIM> aux;

 while(val<fib[i])
  --i;
 val-=fib[i]; aux[i]=1;
 if(i>max)
  max=i;

 for(; i && val; --i) {
  while(val<fib[i])
   --i;
  val-=fib[i];
  aux[i]=1;
 }

 for(i=1; i<=max/2; ++i)
  if(aux[i]!=aux[max-i+1]) return 0;

 return 1;
}

int main() {
    freopen("fibo.in","r",stdin);
    freopen("fibo.out","w",stdout);

    register int i;

 scanf("%d",&N);

    for(i=2; i<=N; ++i)
        sol+=verif(i);

    printf("%d\n",sol);

    return 0;
}