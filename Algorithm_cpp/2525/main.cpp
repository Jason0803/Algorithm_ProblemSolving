#include <cstdio>
int main(){
    int a,b,c;
    scanf("%d %d", &a,&b);
    scanf("%d", &c);
    a += c / 60;
    b += c % 60;
    if(b >= 60){
        a++;
        b %= 60;
    }
    a %= 24;
    printf("%d %d\n", a, b);
    return 0;
}
