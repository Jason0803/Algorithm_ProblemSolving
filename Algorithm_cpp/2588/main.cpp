#include <cstdio>
int main() {
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a*b;
    for(int i=0; i<3; i++){
        printf("%d\n", a*(b%10));
        b /= 10;
    }
    printf("%d\n",c);
    return 0;
}
