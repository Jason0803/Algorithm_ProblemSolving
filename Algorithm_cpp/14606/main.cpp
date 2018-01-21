#include <cstdio>
using namespace std;
int d[11];

int calculate(int n) {
    if(n <= 2) return n-1;
    if(d[n] == 0) d[n] = calculate(n-1) + n-1;
    return d[n];
}
int main(){
    int n;
    scanf("%d", &n);
    d[0] = 0;
    d[1] = 0;
    d[2] = 1;
    
    printf("%d\n", calculate(n));
    return 0;
}
