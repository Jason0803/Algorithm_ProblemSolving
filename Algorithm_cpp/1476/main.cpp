#include <cstdio>

int main() {
    int E, S, M, e, s, m, year;
    scanf("%d %d %d", &E, &S, &M);
    
    year = 1;
    e = 1;
    s = 1;
    m = 1;
    while(true) {
        if(e == E && s == S && m == M) {
            printf("%d\n", year);
            break;
        }
        e++;
        s++;
        m++;
        year++;
        if(e == 16) e = 1;
        if(s == 29) s = 1;
        if(m == 20) m = 1;
    }
    
    return 0;
}
