#include <cstdio>
#include <cstring>
#include <algorithm>

char ch;
int a[1000005],b[1000005],n;
long long d;

long long rest(long long r) {
    int i;
    long long t = 0;
    for(i = a[0]; i >= 1; i--) t = (long long)((long long)t * 10 + a[i]) % r;
    return t;
}

void put(long long v) {
    do {
        b[++b[0]] = (long long)v % 10;
        v = (long long) v / 10;
    } while(v > 0);
}
void add() {
    int i,t = 0;
    for(i = 1; i <= a[0] || i <= b[0] || t > 0; i++) {
        t += a[i] + b[i];
        a[i] = t % 10;
        t /= 10;
        if(i > a[0]) a[0] = i;
    }
}

int main() {
    freopen("next.in","r",stdin);
    freopen("next.out","w",stdout);
    while(1) {
        scanf("%c",&ch);
        if(isdigit(ch))
            a[++a[0]] = ch - '0';
        else
            break;
    }
    std::reverse(a + 1, a + a[0] + 1);
    scanf("\n");
    scanf("%lld",&d);
    long long r = rest(d);
    d = (long long) d - r;
    if(r > 0) {
        put(d);
        add();
    }
    for(int i = a[0]; i >= 1; i--)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}