#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    int *arr = new int[N];
    for(int i = 1; i <= N; i++)
        arr[i-1] = i;
    do {
        for(int i = 0; i < N; i++)
            printf("%d ", arr[i]);
        puts("");
    } while(next_permutation(arr, arr+N));
    return 0;
}
