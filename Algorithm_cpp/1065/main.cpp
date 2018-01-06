#include <cstdio>
int main() {
    int N;
    scanf("%d", &N);
    if(N < 100) {
        printf("%d", N);
    } else {
        //if(N == 1000) N--;
        
        int count = 99;
        int temp, digits[3];
        for(int i = 100; i <= N; i++) {
            temp = i;
            for(int j = 0; j < 3; j++) {
                digits[j] = temp % 10;
                temp /= 10;
            }
            if(digits[0] - digits[1] == digits[1] - digits[2])
                count++;
        }
        printf("%d", count);
    }
    return 0;
}
