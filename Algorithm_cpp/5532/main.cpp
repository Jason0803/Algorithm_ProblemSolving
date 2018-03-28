#include <iostream>
#include <algorithm>
using namespace std;
int L, A, B, C, D, ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> A >> B >> C >> D;
    ans = L - max( (A+C-1)/C, (B+D-1)/D);
    cout << ans << '\n';
    return 0;
}
