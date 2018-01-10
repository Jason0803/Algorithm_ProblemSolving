#include <cstdio>
int d[11];
int main() {
    int T, n;
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i <= 10; i++) {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
    return 0;
}
