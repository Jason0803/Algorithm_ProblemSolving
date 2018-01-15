#include <cstdio>
int buttons[10];

bool ispossible(int x) {
    if(x == 0){
        if(buttons[0]) return true;
        else return false;
    }
    while(x > 0) {
        if(buttons[x%10] == 0)
            return false;
        x /= 10;
    }
    return true;
}
int main() {
    int n, m, input;
    
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i=0; i<10; i++){
        buttons[i] = 1;
    }
    
    for(int i=0; i<m; i++) {
        scanf("%d", &input);
        buttons[input] = 0;
    }
    
    int count = 0;
    
    // 1. 번호 + 직접가는것
    int temp, dist;
    // 1-1. 감소 중에서 찾음
    temp = n;
    while(true){
        if(ispossible(temp)) break;
        else temp--;
    }
    dist = n - temp;
    
    // 1.2 증가 중에서 찾음
    temp = n;
    while(true) {
        if(ispossible(temp)) break;
            else temp++;
    }
    if(dist > (temp - n))
        dist = temp -n;
    
    temp = n;
    while(temp){
        temp /= 10;
        count++;
    }
    
    // 2. 100 번부터 차례로 하는것과 비교
    if(n < 100) {
        if(dist > (100-n))
            dist = 100 - n;
    } else if(n > 100) {
        if(dist > (n-100))
            dist = n - 100;
    } else {
        dist = 0;
        count = 0;
    }
    
    count += dist;
    printf("%d\n", count);
    
    return 0;
}
