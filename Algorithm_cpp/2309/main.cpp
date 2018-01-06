#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int fake_a, fake_b;
    int sum = 0;
    int N[9];
    
    for(int i = 0; i < 9; i++) {
        scanf("%d", &N[i]);
        sum += N[i];
    }
    sort(N, N+9);
    
    for(int i = 0; i < 8; i++) {
        for(int j = i+1; j < 9; j++) {
            if(sum - 100 == N[i] + N[j]) {
                fake_a = i;
                fake_b = j;
                break;
            }
        }
    }
    
    for(int i = 0; i < 9; i++)
        if( i != fake_a && i != fake_b)
            printf("%d\n", N[i]);
    
    return 0;
}
