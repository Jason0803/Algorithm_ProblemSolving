#include <cstdio>
#include <algorithm>

#define MAX 5000000

using namespace std;

int array[MAX];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    sort(array, array+N);
    return 0;
}
