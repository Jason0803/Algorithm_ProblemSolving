#include <cstdio>
int t, a, b, c, ans;
int main() {
    scanf("%d", &t);
    for(int test_case = 1; test_case <= t; test_case++) {
        scanf("%d %d %d", &a, &b, &c);
        if(a == b && b == c) {
            ans = a;
        } else if(a == b) {
            ans = c;
        } else if(a == c) {
            ans = b;
        } else if(b == c) {
            ans = a;
        }
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
