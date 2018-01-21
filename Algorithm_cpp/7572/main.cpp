#include <cstdio>
int main() {
    char ten_gan[] = {'0','1','2','3','4','5','6','7','8','9'};
    char twelve_gi[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'}; // 65 ~ ..

    int n;
    scanf("%d", &n);
    n += 56;
    n %= 60;
    printf("%c%c\n",twelve_gi[n%12],ten_gan[n%10]);

    return 0;
}
