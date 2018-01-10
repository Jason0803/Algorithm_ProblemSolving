#include <cstdio>
using namespace std;
int check[1000000];
int pow(int x, int p) {
    int result = 1;
    for(int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}
int next(int x, int p) {
    int result = 0;
    while(x > 0) {
        result += pow(x%10, p);
        x /= 10;
    }
    return result;
}
int dfs(int a, int p, int count) {
    if(check[a] != 0) {
        return check[a] -1;
    }
    check[a] = count;
    int b = next(a, p);
    return dfs(b, p, count+1);
}
int main() {
    int A, P;
    scanf("%d %d", &A, &P);
    printf("%d", dfs(A, P, 1));

    return 0;
}
