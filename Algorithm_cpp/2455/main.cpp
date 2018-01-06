#include <cstdio>

int main() {
    int in, out;
    int current = 0;
    int max = 0;
    for(int station = 1; station <= 4; station++) {
        scanf("%d %d", &out, &in);
        current += in - out;
        if(current > max) {
            max = current;
        }
    }
    printf("%d\n", max);
    return 0;
}
