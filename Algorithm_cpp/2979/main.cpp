#include <iostream>
using namespace std;
int A, B, C, time_stream[101], factor[4], st, fn, ans;
int main() {
    cin >> factor[1] >> factor[2] >> factor[3];
    for(int i=0; i<3; i++) {
        cin >> st >> fn;
        for(int i=st; i<fn; i++) time_stream[i]++;
    }
    for(int i=1; i<=100; i++) {
        ans += time_stream[i] * factor[time_stream[i]];
    }
    cout << ans << '\n';
    return 0;
}
