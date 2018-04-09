#include <iostream>
using namespace std;
 int combination(int n, int r) {
     if(n == r || r == 0) return 1;
     else return combination(n - 1, r - 1) + combination(n - 1, r);
 }
int T, N, M, K, ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> N >> K >> M;
        ans = combination(N, M) + combination(N, K-M);
        cout << ans%1003001 << '\n';
    }
    return 0;
}
