#include <cstdio>
#include <algorithm>

using namespace std;

#define inFile "sirag.in"
#define outFile "sirag.out"
#define MAX_N 100001

int v[MAX_N], k, p;

bool CanFill(long long x) {
    int i;
    long long s = 0;

    for(i = 1; i <= k; i++) {
        if(x >= v[i])
            s += v[i];
        else
            s += x;
    }
    return s >= p*x;
}

long long getRemainder(long long x) {
    int i;
    long long s = 0;

    for(i = 1; i <= k; i++) {
        if(x >= v[i])
            s += v[i];
        else
            s += x + 1;
    }

    return s;
}

int main() {
    freopen(inFile, "r", stdin);
    freopen(outFile, "w", stdout);

    int n, i, j, last;
    long long s = 0, start, mid, fin;

    scanf("%d %d", &k, &p);

    for(i = 1; i <= k; i++) {
        scanf("%d", &v[i]);
        s += v[i];
    }

    start = 1;
    fin = s;

    while(start <= fin) {
        mid = (start+fin)>>1;
        if(CanFill(mid))
            start = mid+1, last = mid;
        else
            fin = mid-1;
    }

    long long rem = getRemainder(last);

    printf("%lld\n", rem);

    return 0;
}