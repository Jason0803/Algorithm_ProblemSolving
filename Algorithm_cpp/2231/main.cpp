#include <cstdio>
int main() {
    int N, M, temp;
    scanf("%d", &N);
    if(N>10) {
        for(int i = 10; i < N; i++) {
            M = i;
            temp = M;
            while(M>0) {
                temp += (M % 10);
                M /= 10;
            }
            if(temp == N) {
                M = i;
                break;
            }
        }
    } else M = 0;
    printf("%d", M);
    return 0;
}
