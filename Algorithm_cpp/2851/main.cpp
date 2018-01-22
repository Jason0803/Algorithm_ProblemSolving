#include <cstdio>
bool check[1001];
int main() {
    int input;
    int sum = 0;
    int score = 0;
    for(int i=0; i<10; i++){
        scanf("%d", &input);
        sum += input;
        if(sum == 100) {
            printf("100\n");
            return 0;
        }
        check[sum] = true;
    }
    for(int i=1; i<100; i++){
        if(check[100-i]) score = 100-i;
        if(check[100+i]) score = 100+i;
        if(score != 0) break;
    }
    printf("%d\n", score);
    return 0;
}
