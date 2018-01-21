#include <cstdio>
int main(){
    int a,b,c,d;
    scanf("%d %d %d", &a,&b,&c);
    scanf("%d", &d);
    a += d / 3600;
    d %= 3600;
    b += d / 60;
    c += d % 60;
    if(c >= 60)
        b++;
    if(b >= 60)
        a++;
    a %= 24;
    b %= 60;
    c %= 60;
    printf("%d %d %d\n", a, b, c);
    return 0;
}

