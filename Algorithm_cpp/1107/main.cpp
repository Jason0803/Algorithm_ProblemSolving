#include <cstdio>
#include <cstdlib>
using namespace std;
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
    int dist;
    int count = 0; // 누른 횟수

    // 1. 100 번부터 차례로 하는것과 비교
    dist = abs(n-100);
    
    // 2. N과 최대 가능한 수 까지 구한 뒤 1. 과 비교
    for(int i=0; i<=1000000; i++) {
        int j = i;
        int length = 0;
        if(ispossible(j)) {
            count = abs(n-j);
            if(j < 10) length = 1;
            else {
                while(j) {
                length++;
                j /= 10;
                }
            }
            if(dist > count + length)
                dist = count + length;
        }
    }

    printf("%d\n", dist);
    return 0;
}
