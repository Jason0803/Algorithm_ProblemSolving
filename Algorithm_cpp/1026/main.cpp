#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;
int N, ans;
int A[51], B[51];
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
    
    for(int i=0; i<N; i++)
        scanf("%d", &B[i]);
    
    sort(A, A+N);
    sort(B, B+N, greater<int>());
    
    for(int i=0; i<N; i++) {
        ans += A[i] * B[i];
    }
    
    printf("%d\n", ans);
    return 0;
}
